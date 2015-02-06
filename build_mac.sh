git submodule init
git submodule update

cd Submodules/JUCE/
git checkout master
git pull
cd ../../

cd Submodules/danlin_modules
git checkout master
git pull
cd ../../

/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Standalone/Soundboard-Standalone.jucer
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Plugin/Soundboard-Plugin.jucer

cd Standalone/Builds/MacOSX/
xcodebuild
cd ../../../

cd Plugin/Builds/MacOSX/
xcodebuild
cd ../../../
