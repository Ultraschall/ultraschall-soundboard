Soundboard
==========

Ultraschall Soundboard VST das Soundboard für Podcaster.

[![Build Status](https://travis-ci.org/Ultraschall/Soundboard.svg?branch=develop)](https://travis-ci.org/Ultraschall/Soundboard)

## Installation

- Entpacken des ZIP-Archivs
- Verschieben der Datei Soundboard.vst nach: USER/Library/Audio/Plug-Ins/VST
- Die eventuell schon vorhandene, alte Version unter HDD/Library/Audio/Plug-Ins/VST bitte löschen

## Entwickler HowTo

Den Sourcecode bekommst du wie folgend:
```
git clone https://github.com/Ultraschall/Soundboard.git Soundboard
cd Soundboard
git submodule init 
git submodule update
```

Wenn du dich noch nicht mit dem JUCE Framework auskennst, kannst du dich hier http://www.juce.com/learn/getting-started darüber informieren.

Um das VST Plugin übersetzen zu können brauchst das VST STK von Steinberg. (https://www.steinberg.net/de/company/developer.html)

Das Soundboard sollte unter Mac OS X, Linux und Windows übersetzbar sein. Die passenden Projektdateien findet ihr unter ./Builds.

Über dein Feedback freuen wir uns natürlich.

### Linux (Ubuntu)

Folgende Pakete werden benötigt.
```
sudo apt-get -y install build-essential
sudo apt-get -y install libfreetype6-dev
sudo apt-get -y install libx11-dev
sudo apt-get -y install libxinerama-dev
sudo apt-get -y install libxcursor-dev
sudo apt-get -y install mesa-common-dev
sudo apt-get -y install libasound2-dev
sudo apt-get -y install freeglut3-dev
sudo apt-get -y install libxcomposite-dev 
sudo apt-get -y install libxrandr-dev
sudo apt-get -y install libsdl1.2-dev
sudo apt-get -y install libc++-dev

sudo apt-get -y install clang
sudo update-alternatives --config c++
```
Zum kompilieren muss clang verwerdent werden! GCC und libstdc++ untersetuetzen einige Features des Soundboard Sourcecodes noch nicht.

Von https://github.com/FortAwesome/Font-Awesome/tree/master/fonts muss die Font fontawesome-webfont.ttf installiert werden. (Leider geht die eingebettete Font nicht unter Linux)

Nach dem kompilieren muss die Datei Soundboard.so unter /usr/local/lib/lxvst/ kopiert werden.

## Windows

Die Binaries kommen am besten unter C:\Program Files\VstPlugins
