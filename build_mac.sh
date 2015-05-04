git submodule init > /dev/null
git submodule update > /dev/null

cd Submodules/JUCE/
git checkout master > /dev/null
git pull > /dev/null
cd ../../

cd Submodules/danlin_modules
git checkout master > /dev/null
git pull > /dev/null
cd ../../

/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Standalone/Soundboard-Standalone.jucer > /dev/null
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Plugin/Soundboard-Plugin.jucer > /dev/null

cd Standalone/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../

cd Plugin/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../
