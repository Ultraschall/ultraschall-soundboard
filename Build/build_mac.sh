#!/bin/sh
echo "Cleanup"
rm -rf Files
mkdir Files
mkdir Files/Standalone
mkdir Files/VST
mkdir Files/AudioUnit

echo "Update Git Submodules"
git submodule init > /dev/null
git submodule update > /dev/null

cd Submodules/danlin_modules
git checkout master > /dev/null
git pull > /dev/null
cd ../../

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Introjucer/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../../../

echo "Update Projects"
./Submodules/JUCE/extras/Introjucer/Builds/MacOSX/build/Release/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Tests/Tests.jucer > /dev/null
./Submodules/JUCE/extras/Introjucer/Builds/MacOSX/build/Release/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Standalone/Standalone.jucer > /dev/null
./Submodules/JUCE/extras/Introjucer/Builds/MacOSX/build/Release/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Plugin/Plugin.jucer > /dev/null

echo "UnitTesting"
cd Projects/Tests/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../
Projects/Tests/Builds/MacOSX/build/Release/Tests

echo "Build Standalone"
cd Projects/Standalone/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../
cp -rf Projects/Standalone/Builds/MacOSX/build/Release/Soundboard.app Files/Standalone

echo "Build Plugin"
cd Projects/Plugin/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../
cp -rf ~/Library/Audio/Plug-Ins/VST/Soundboard.vst Files/VST
cp -rf ~/Library/Audio/Plug-Ins/Components/Soundboard.component Files/AudioUnit

echo "Compress Output"
cd Files/Standalone
zip -r ../Soundboard.App.Mac.OS.X.zip Soundboard.app
cd ../VST
zip -r ../Soundboard.VST.Mac.OS.X.zip Soundboard.vst
cd ../AudioUnit
zip -r ../Soundboard.AudioUnit.Mac.OS.X.zip Soundboard.component
cd ..

