@echo off
echo "Cleanup"
rmdir Files /q /s
mkdir Files
mkdir Files\Standalone
mkdir Files\VST

echo "Update Git Submodules"
git submodule init > NUL
git submodule update > NUL

cd Submodules/JUCE/
git checkout master > NUL
git pull > NUL
cd ../../

cd Submodules/danlin_modules
git checkout master > NUL
git pull > NUL
cd ../../

cd Submodules/danlin_modules
git checkout master > NUL
git pull > NUL
cd ../../

echo "Bootstrap Tools"
cd Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd ../../../../../../

echo "Update Projects"
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Tests/Tests.jucer
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Standalone/Standalone.jucer
"./Submodules/JUCE/extras/Introjucer/Builds/VisualStudio2015/Release/The Introjucer.exe" --resave Projects/Plugin/Plugin.jucer

echo "UnitTesting"
cd Projects/Tests/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd Release
Tests.exe
cd ../../../../../

echo "Build Standalone"
cd Projects/Standalone/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd ../../../../
copy Projects\Standalone\Builds\VisualStudio2015\Release\Soundboard.exe Files\Standalone
cd Files\Standalone
powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('.', '../Soundboard.App.Win32.zip'); }"
cd ../../

echo "Build Plugin"
cd Projects/Plugin/Builds/VisualStudio2015/
msbuild /t:clean > NUL
msbuild /clp:ErrorsOnly;ShowTimestamp /property:Configuration=Release /m /nologo
cd ../../../../
copy Projects\Plugin\Builds\VisualStudio2015\Release\Soundboard.dll Files\VST
cd Files\VST
powershell.exe -nologo -noprofile -command "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('.', '../Soundboard.VST.Win32.zip'); }"
cd ../../
