#addin nuget:?package=Cake.XCode
#addin nuget:?package=Cake.DoInDirectory
#tool nuget:?package=WiX.Toolset

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

///////////////////////////////////////////////////////////////////////////////
// SETUP / TEARDOWN
///////////////////////////////////////////////////////////////////////////////

Setup(context =>
{
    if (IsRunningOnUnix()) {
        // TODO: 19.11.2016 dnl -> detect macOS and Linux here
	    os = "macOS";
    }
    if (verbosity != "Verbose" || verbosity != "Diagnostic") {
        verbose = false;
    }
    Information("Setup");
});

Teardown(context =>
{
    Information("Bye Bye");
});


///////////////////////////////////////////////////////////////////////////////
// TASK DEFINITIONS
///////////////////////////////////////////////////////////////////////////////

Task("Install")
    .Does(() => {});

Task("Bootstrap")
    .Does(() => {
	    if(os == "Windows") {
            Information("Build Projucer");
            MSBuild("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/Projucer.sln", settings => settings
                .SetVerbosity(Verbosity.Quiet)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
            Information("Create Projects");
            StartProcess("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/x64/Release/Projucer.exe", "--resave Projects/Standalone/Standalone.jucer");
            StartProcess("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/x64/Release/Projucer.exe", "--resave Projects/Plugin/Plugin.jucer");
	    } else if (os == "macOS") {
            Information("Build Projucer");
            DoInDirectory("./Submodules/JUCE/extras/Projucer/Builds/MacOSX", () => {
                XCodeBuild(new XCodeBuildSettings {
		            Verbose = verbose,
		            Configuration = configuration
		        });
            });
            Information("Create Projects");
            StartProcess("./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer", "--resave Projects/Standalone/Standalone.jucer");
            StartProcess("./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer", "--resave Projects/Plugin/Plugin.jucer");
	    }
    });

Task("Standalone")
    .Does(() => {
        Information("Build Standalone Application");
	    if(os == "Windows") {
            MSBuild("./Projects/Standalone/Builds/VisualStudio2015/Soundboard.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
        } else if (os == "macOS") {
	        DoInDirectory("./Projects/Standalone/Builds/MacOSX", () => {
	            XCodeBuild(new XCodeBuildSettings {
		            Verbose = verbose,
		            Configuration = configuration
		        });
	        });
	    }
    });

Task("Plugin")
    .Does(() => {
        if (os == "Windows") {
            Information("Build Plugin 32bit");
	        MSBuild("./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.Win32));
	    } else if (os == "macOS") {
            Information("Build Plugin");
	        DoInDirectory("./Projects/Plugin/Builds/MacOSX", () => {
                XCodeBuild(new XCodeBuildSettings {
                    Verbose = verbose,
                    Configuration = configuration
                });
            });
	    }
    });

Task("Plugin64")
    .Does(() => {
	    if (os == "Windows") {
            Information("Build Plugin 64bit");
            MSBuild("./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln", settings => settings
                .SetVerbosity(Verbosity.Minimal)
                .WithTarget("Build")
                .SetConfiguration(configuration)
                .SetPlatformTarget(PlatformTarget.x64));
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
	    }
    });

Task("Build")
    .IsDependentOn("Bootstrap")
    .IsDependentOn("Standalone")
    .IsDependentOn("Plugin")
    .IsDependentOn("Plugin64")
    .Does(() => {});

//////////////////////////////////////////////////////////////////////
// TASK TARGETS
//////////////////////////////////////////////////////////////////////

Task("Default")
    .IsDependentOn("Build");

//////////////////////////////////////////////////////////////////////
// EXECUTION
//////////////////////////////////////////////////////////////////////

RunTarget(target);
