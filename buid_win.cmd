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

"c:/bin/The Introjucer.exe" --resave Standalone/Soundboard-Standalone.jucer
"c:/bin/The Introjucer.exe" --resave Plugin/Soundboard-Plugin.jucer

cd Standalone/Builds/VisualStudio2013/
msbuild
cd ../../../

cd Plugin/Builds/VisualStudio2013/
msbuild
cd ../../../
