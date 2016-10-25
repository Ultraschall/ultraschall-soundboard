#!/bin/sh
echo "Update Git Submodules"
git submodule init > /dev/null
git submodule update > /dev/null

cd Submodules/danlin_modules
git checkout master > /dev/null
git pull > /dev/null
cd ../../

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Projucer/Builds/Linux/
make -j4
cd ../../../../../../

echo "Update Projects"
./Submodules/JUCE/extras/Projucer/Builds/Linux/build/Projucer --resave Projects/Tests/Tests.jucer > /dev/null

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

echo "UnitTesting"
cd Projects/Tests/Builds/Linux/
make -j4
cd ../../../../
./Projects/Tests/Builds/Linux/build/Tests
