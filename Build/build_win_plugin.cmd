@echo off

echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

echo "Bootstrap Tools"
msbuild /clp:ErrorsOnly;ShowTimestamp /t:build /p:Configuration=Release /p:Platform="x64" /m /nologo "./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/Projucer.sln"

echo "Update Projects"
"./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/x64/Release/Projucer.exe" --resave Projects/Plugin/Plugin.jucer

echo "Upgrade Projects to Visual Studio 2017"
devenv .\Projects\Plugin\Builds\VisualStudio2015\Plugin.sln /Upgrade

echo "Build Plugin 64bit"
msbuild /clp:ErrorsOnly;ShowTimestamp /t:build /p:Configuration=Release /p:Platform="x64" /m /nologo "./Projects/Plugin/Builds/VisualStudio2015/Plugin.sln"

