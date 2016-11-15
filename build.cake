///////////////////////////////////////////////////////////////////////////////
// ARGUMENTS
///////////////////////////////////////////////////////////////////////////////

var target = Argument<string>("target", "Default");
var configuration = Argument<string>("configuration", "Release");

///////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// SETUP / TEARDOWN
///////////////////////////////////////////////////////////////////////////////

Setup(context =>
{
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
        Information("Build Projucer");
        MSBuild("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/Projucer.sln", settings => settings
            .SetVerbosity(Verbosity.Quiet)
            .WithTarget("Build")
            .SetConfiguration(configuration)
            .SetPlatformTarget(PlatformTarget.x64));
        Information("Create Projects");
        StartProcess("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/x64/Release/Projucer.exe", "--resave Projects/Standalone/Standalone.jucer");
        StartProcess("./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/x64/Release/Projucer.exe", "--resave Projects/Plugin/Plugin.jucer");
    });

Task("Standalone")
    .Does(() => {
        Information("Build Standalone Application");
        MSBuild("./Projects/Standalone/Builds/VisualStudio2015/Soundboard.sln", settings => settings
            .SetVerbosity(Verbosity.Minimal)
            .WithTarget("Build")
            .SetConfiguration(configuration)
            .SetPlatformTarget(PlatformTarget.x64));
    });

Task("Plugin")
    .Does(() => {
        Information("Build Plugin 32bit");
        MSBuild("./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln", settings => settings
            .SetVerbosity(Verbosity.Minimal)
            .WithTarget("Build")
            .SetConfiguration(configuration)
            .SetPlatformTarget(PlatformTarget.Win32));
    });

Task("Plugin64")
    .Does(() => {
        Information("Build Plugin 64bit");
        MSBuild("./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln", settings => settings
            .SetVerbosity(Verbosity.Minimal)
            .WithTarget("Build")
            .SetConfiguration(configuration)
            .SetPlatformTarget(PlatformTarget.x64));
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
