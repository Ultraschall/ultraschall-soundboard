@echo off
echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

cd Submodules/danlin_modules
git checkout master > NUL
git pull > NUL
cd ../../

cd Submodules/danlin_modules
git checkout master > NUL
git pull > NUL
cd ../../

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd ../../../../../../

echo "Update Projects"
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Tests/Tests.jucer

echo "UnitTesting"
cd Projects/Tests/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd Release
Tests.exe
cd ../../../../../
