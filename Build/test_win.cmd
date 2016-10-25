@echo off

echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

echo "Bootstrap Tools"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="Win32" /m /nologo "./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/Projucer.sln"

echo "Update Projects"
"./Submodules/JUCE/extras/Projucer/Builds/VisualStudio2015/Release/Projucer.exe" --resave Projects/Tests/Tests.jucer

echo "Build Tests"
msbuild /t:clean "./Projects/Tests/Builds/VisualStudio2015/Tests.sln" > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="Win32" /m /nologo "./Projects/Tests/Builds/VisualStudio2015/Tests.sln"
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /p:Platform="x64" /m /nologo "./Projects/Tests/Builds/VisualStudio2015/Tests.sln"

echo "Testing"
"./Projects/Tests/Builds/VisualStudio2015/x64/Release/Tests.exe"
"./Projects/Tests/Builds/VisualStudio2015/Release/Tests.exe"