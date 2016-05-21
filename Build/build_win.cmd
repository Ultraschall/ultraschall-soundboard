@echo off

echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

echo "Bootstrap Tools"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="Win32" /m /nologo "./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/The Introjucer.sln"

echo "Update Projects"
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Standalone/Standalone.jucer
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Plugin/Plugin.jucer

echo "Build Standalone"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="x64" /m /nologo "./Projects/Standalone/Builds/VisualStudio2015/Soundboard.sln"

echo "Build Plugin 32bit"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="win32" /m /nologo "./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln"

echo "Build Plugin 64bit"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="x64" /m /nologo "./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln"

echo "Build Installer"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo "./Projects/Installer/Installer.wixproj"
