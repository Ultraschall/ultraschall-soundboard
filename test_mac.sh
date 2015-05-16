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

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Introjucer/Builds/MacOSX/
xcodebuild -sdk macosx10.9 -configuration Release > /dev/null
cd ../../../../../../

echo "Update Projects"
./Submodules/JUCE/extras/Introjucer/Builds/MacOSX/build/Debug/Introjucer.app/Contents/MacOS/Introjucer --resave Projects/Tests/Tests.jucer > /dev/null

echo "UnitTesting"
cd Projects/Tests/Builds/MacOSX/
xcodebuild -sdk macosx10.9 > /dev/null
cd ../../../../
Projects/Tests/Builds/MacOSX/build/Debug/Tests
