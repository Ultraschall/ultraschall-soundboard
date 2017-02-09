#!/bin/sh
echo "Cleanup"
rm -rf Files
mkdir Files
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
./Submodules/JUCE/extras/Projucer/Builds/MacOSX/build/Release/Projucer.app/Contents/MacOS/Projucer --resave Projects/Plugin/Plugin.jucer > /dev/null

echo "Build Plugin"
cd Projects/Plugin/Builds/MacOSX/
xcodebuild -configuration Release > /dev/null
cd ../../../../
cp -rf ~/Library/Audio/Plug-Ins/VST/Soundboard.vst Files/VST
cp -rf ~/Library/Audio/Plug-Ins/Components/Soundboard.component Files/AudioUnit

echo "Compress Output"
cd Files//VST
zip -r ../Soundboard.VST.Mac.OS.X.zip Soundboard.vst
cd ../AudioUnit
zip -r ../Soundboard.AudioUnit.Mac.OS.X.zip Soundboard.component
cd ..

