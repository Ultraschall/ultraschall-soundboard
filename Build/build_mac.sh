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

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Projucer/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../../../

echo "Update Projects"
./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer --resave Projects/Tests/Tests.jucer > /dev/null
./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer --resave Projects/Standalone/Standalone.jucer > /dev/null
./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer --resave Projects/Plugin/Plugin.jucer > /dev/null

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
cp -rf ./Projects/Plugin/Builds/MacOSX/build/Release/Soundboard.vst Files/VST
cp -rf ./Projects/Plugin/Builds/MacOSX/build/Release/Soundboard.component Files/AudioUnit

echo "Compress Output"
cd Files/Standalone
zip -r ../Soundboard.App.Mac.OS.X.zip Soundboard.app
cd ../AudioUnit
zip -r ../Soundboard.AudioUnit.Mac.OS.X.zip Soundboard.component
cd ..

