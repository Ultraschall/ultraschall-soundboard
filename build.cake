#addin "Cake.XCode"
#addin "Cake.DoInDirectory"
#addin "Cake.FileHelpers"
#tool "WiX.Toolset"


///////////////////////////////////////////////////////////////////////////////
// ARGUMENTS
///////////////////////////////////////////////////////////////////////////////

var target = Argument<string>("target", "Default");
var configuration = Argument<string>("configuration", "Release");
var verbosity = Argument<string>("verbosity", "Verbose");

///////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
///////////////////////////////////////////////////////////////////////////////

string os = "Windows";
bool verbose = true;
string projucer = "";
string artifacts = "./Artifacts";

///////////////////////////////////////////////////////////////////////////////
// SETUP / TEARDOWN
///////////////////////////////////////////////////////////////////////////////

Setup(context =>
{
    if (IsRunningOnUnix()) {
        // TODO: 19.11.2016 dnl -> detect macOS and Linux here
	    os = "macOS";
    }

    Information(Environment.Platform.Family);

    if (os == "Windows") {
        projucer = "./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2017/x64/Release/Projucer.exe";
    } else if (os == "macOS") {
        projucer = "./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer";
    }
    if (verbosity != "Verbose" || verbosity != "Diagnostic") {
        verbose = false;
    }
    EnsureDirectoryExists(artifacts);
    CleanDirectory(artifacts);
    Information("Setup");
});

Teardown(context =>
{
    Information("Bye Bye");
});


///////////////////////////////////////////////////////////////////////////////
// TASK DEFINITIONS
///////////////////////////////////////////////////////////////////////////////
Task("Prepare")
    .WithCriteria(() => !FileExists(projucer))
    .Does(() => {
        RunTarget("Bootstrap");
    });

Task("Bootstrap")
    .Does(() => {
        ReplaceTextInFiles("./Submodules/JUCE/extras/Projucer/JuceLibraryCode/AppConfig.h", "JUCER_ENABLE_GPL_MODE 0", "JUCER_ENABLE_GPL_MODE 1");
	    if(os == "Windows") {
            Information("Build Projucer");
            MSBuild("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2017/Projucer.sln", settings => settings
                .SetVerbosity(Verbosity.Quiet)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
	    } else if (os == "macOS") {
            Information("Build Projucer");
            DoInDirectory("./Submodules/JUCE/extras/Projucer/Builds/MacOSX", () => {
                XCodeBuild(new XCodeBuildSettings {
		            Verbose = verbose,
		            Configuration = configuration
		        });
            });
	    }
    });

Task("Standalone")
    .Does(() => {
        Information("Build Standalone Application");
        StartProcess(projucer, "--resave Projects/Standalone/Standalone.jucer");
	    if(os == "Windows") {
            EnsureDirectoryExists(artifacts + "/Standalone");
            MSBuild("./Projects/Standalone/Builds/VisualStudio2017/Soundboard.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
            CopyFile("./Projects/Standalone/Builds/VisualStudio2017/x64/Release/Soundboard.exe", artifacts + "/Standalone/Soundboard.exe");
            Zip(artifacts + "/Standalone", artifacts + "/Soundboard.Standalone.Windows.zip");
            DeleteDirectory(artifacts + "/Standalone", true);
        } else if (os == "macOS") {
            EnsureDirectoryExists(artifacts + "/Standalone");
	        DoInDirectory("./Projects/Standalone/Builds/MacOSX", () => {
	            XCodeBuild(new XCodeBuildSettings {
		            Verbose = verbose,
		            Configuration = configuration
		        });
	        });
            CopyDirectory("./Projects/Standalone/Builds/MacOSX/build/Release/Soundboard.app", artifacts + "/Standalone/Soundboard.app");
            Zip(artifacts + "/Standalone", artifacts + "/Soundboard.Standalone.macOS.zip");
            DeleteDirectory(artifacts + "/Standalone", true);
	    }
    });

Task("Plugin")
    .Does(() => {
        StartProcess(projucer, "--resave Projects/Plugin/Plugin.jucer");
        if (os == "Windows") {
            EnsureDirectoryExists(artifacts + "/VST");
            Information("Build Plugin 32bit");
	        MSBuild("./Projects/Plugin/Builds/VisualStudio2017/Plugin.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.Win32));
            CopyFile("./Projects/Plugin/Builds/VisualStudio2017/Release/Soundboard32.dll", artifacts + "/VST/Soundbaord32.dll");
            Information("Build Plugin 64bit");
            MSBuild("./Projects/Plugin/Builds/VisualStudio2017/Plugin.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
            CopyFile("./Projects/Plugin/Builds/VisualStudio2017/x64/Release/Soundboard64.dll", artifacts + "/VST/Soundboard64.dll");
            Zip(artifacts + "/VST", artifacts + "/Soundboard.VST.Windows.zip");
            DeleteDirectory(artifacts + "/VST", true);
	    } else if (os == "macOS") {
            EnsureDirectoryExists(artifacts + "/AudioUnit");
            EnsureDirectoryExists(artifacts + "/VST");
            Information("Build Plugin");
	        DoInDirectory("./Projects/Plugin/Builds/MacOSX", () => {
                XCodeBuild(new XCodeBuildSettings {
                    Verbose = verbose,
                    Configuration = configuration
                });
            });
            CopyDirectory(EnvironmentVariable("HOME") + "/Library/Audio/Plug-Ins/Components/Soundboard.component", artifacts + "/AudioUnit/Soundboard.component");
            CopyDirectory(EnvironmentVariable("HOME") + "/Library/Audio/Plug-Ins/VST/Soundboard.vst", artifacts + "/VST/Soundboard.vst");
            Zip(artifacts + "/AudioUnit", artifacts + "/Soundboard.AudioUnit.macOS.zip");
            Zip(artifacts + "/VST", artifacts + "/Soundboard.VST.macOS.zip");
            DeleteDirectory(artifacts + "/AudioUnit", true);
            DeleteDirectory(artifacts + "/VST", true);
	    }
    });

Task("Installer")
    .Does(() => {
        if (os == "Windows") {
            Information("Build Installer");
            DoInDirectory("./Projects/Installer", () => {
                WiXCandle("./*.wxs", new CandleSettings {
                    Architecture = Architecture.X64,
                    Verbose = verbose,
                    Extensions = new [] {"WixUIExtension"},
                    OutputDirectory = "./bin/" + configuration
                });

                WiXLight("./bin/" + configuration + "/Product.wixobj",  new LightSettings {
                    Extensions = new [] {"WixUIExtension"},
                    OutputFile = "./bin/" + configuration + "/Soundboard"
                });

                WiXLight("./bin/" + configuration + "/Module.wixobj",  new LightSettings {
                    OutputFile = "./bin/" + configuration + "/Soundboard"
                });
            });
            CopyFile("./Projects/Installer/bin/Release/Soundboard.msi", artifacts + "/Soundboard.msi");
            CopyFile("./Projects/Installer/bin/Release/Soundboard.msm", artifacts + "/Soundboard.msm");
	    }
    });

Task("Build")
    .IsDependentOn("Prepare")
    .IsDependentOn("Standalone")
    .IsDependentOn("Plugin")
    .IsDependentOn("Installer");

//////////////////////////////////////////////////////////////////////
// TASK TARGETS
//////////////////////////////////////////////////////////////////////

Task("Default")
    .IsDependentOn("Build");

//////////////////////////////////////////////////////////////////////
// EXECUTION
//////////////////////////////////////////////////////////////////////

RunTarget(target);
