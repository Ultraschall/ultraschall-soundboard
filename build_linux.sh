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
cd Submodules/JUCE/extras/Introjucer/Builds/Linux/
make -j4
cd ../../../../../../

echo "Update Projects"
./Submodules/JUCE/extras/Introjucer/Builds/Linux/build/Introjucer --resave Projects/Tests/Tests.jucer > /dev/null
./Submodules/JUCE/extras/Introjucer/Builds/Linux/build/Introjucer --resave Projects/Standalone/Standalone.jucer > /dev/null
./Submodules/JUCE/extras/Introjucer/Builds/Linux/build/Introjucer --resave Projects/Plugin/Plugin.jucer > /dev/null

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "UnitTesting"
cd Projects/Tests/Builds/Linux/
make -j4
cd ../../../../
./Projects/Tests/Builds/Linux/build/Tests

echo "Build Standalone"
cd Projects/Standalone/Builds/Linux/
make -j4
cd ../../../../

echo "Build Plugin"
cd Projects/Plugin/Builds/Linux/
make -j4
cd ../../../../
