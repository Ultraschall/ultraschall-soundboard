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
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Tests/Tests.jucer > /dev/null
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Standalone/Soundboard-Standalone.jucer > /dev/null
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Plugin/Soundboard-Plugin.jucer > /dev/null

cd Projects/Tests/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../../
Projects/Tests/Builds/MacOSX/build/Debug/Tests

cd Projects/Standalone/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../../

cd Projects/Plugin/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../../
