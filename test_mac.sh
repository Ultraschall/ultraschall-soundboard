echo "Update Git Submodules"
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

echo "Update Projects"
/Applications/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Tests/Tests.jucer > /dev/null

echo "UnitTesting"
cd Projects/Tests/Builds/MacOSX/
xcodebuild > /dev/null
cd ../../../../
Projects/Tests/Builds/MacOSX/build/Debug/Tests
