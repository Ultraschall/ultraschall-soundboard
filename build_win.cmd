@echo off
echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

cd Submodules/JUCE/
git checkout master > NUL
git pull > NUL
cd ../../

cd Submodules/danlin_modules
git checkout master > NUL
git pull > NUL
cd ../../

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2013/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /m /nologo
cd ../../../../../../

echo "Update Projects"
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2013/Debug/The Introjucer.exe" --resave Projects/Tests/Tests.jucer
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2013/Debug/The Introjucer.exe" --resave Projects/Standalone/Standalone.jucer
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2013/Debug/The Introjucer.exe" --resave Projects/Plugin/Plugin.jucer

echo "UnitTesting"
cd Projects/Tests/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /m /nologo
cd Debug
Tests.exe
cd ../../../../../

echo "Build Standalone"
cd Projects/Standalone/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /m /nologo
cd ../../../../

echo "Build Plugin"
cd Projects/Plugin/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /m /nologo
cd ../../../../
