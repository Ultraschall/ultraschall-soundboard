Soundboard
==========

Ultraschall Soundboard VST das Soundboard für Podcaster.

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
sudo apt-get -y install libxinerama-dev
sudo apt-get -y install libxcursor-dev
sudo apt-get -y install libasound2-dev
```

Von https://github.com/FortAwesome/Font-Awesome/tree/master/fonts muss die Font fontawesome-webfont.ttf installiert werden. (Leider geht die eingebettete Font nicht unter Linux)

Nach dem kompilieren muss die Datei Soundboard.so unter /usr/local/lib/lxvst/ kopiert werden.

## Windows

Die Binaries kommen am besten unter C:\Program Files\Steinberg\VstPlugins

## MIDI Note Kommandos

HEX|Note|Funktion|Player
---|----|--------|------
00|C -1|Play / Stop|1
01|C#-1|Play / Stop|2
02|D -1|Play / Stop|3
03|Eb-1|Play / Stop|4
04|E -1|Play / Stop|5
05|F -1|Play / Stop|6
06|F#-1|Play / Stop|7
07|G -1|Play / Stop|8
08|G#-1|Play / Stop|9
09|A -1|Play / Stop|10
0A|Bb-1|Play / Stop|11
0B|B -1|Play / Stop|12
0C|C 0|Play / Stop|13
0D|C# 0|Play / Stop|14
0E|D 0|Play / Stop|15
0F|Eb 0|Play / Stop|16
10|E 0|Play / Stop|17
11|F 0|Play / Stop|18
12|F# 0|Play / Stop|19
13|G 0|Play / Stop|20
14|G# 0|Play / Stop|21
15|A 0|Play / Stop|22
16|Bb 0|Play / Stop|23
17|B 0|Play / Stop|24
18|C 1|Play / Pause|1
19|C# 1|Play / Pause|2
1A|D 1|Play / Pause|3
1B|Eb 1|Play / Pause|4
1C|E 1|Play / Pause|5
1D|F 1|Play / Pause|6
1E|F# 1|Play / Pause|7
1F|G 1|Play / Pause|8
20|G# 1|Play / Pause|9
21|A 1|Play / Pause|10
22|Bb 1|Play / Pause|11
23|B 1|Play / Pause|12
24|C 2|Play / Pause|13
25|C# 2|Play / Pause|14
26|D 2|Play / Pause|15
27|Eb 2|Play / Pause|16
28|E 2|Play / Pause|17
29|F 2|Play / Pause|18
2A|F# 2|Play / Pause|19
2B|G 2|Play / Pause|20
2C|G# 2|Play / Pause|21
2D|A 2|Play / Pause|22
2E|Bb 2|Play / Pause|23
2F|B 2|Play / Pause|24
30|C 3|Play / Fade-Out|1
31|C# 3|Play / Fade-Out|2
32|D 3|Play / Fade-Out|3
33|Eb 3|Play / Fade-Out|4
34|E 3|Play / Fade-Out|5
35|F 3|Play / Fade-Out|6
36|F# 3|Play / Fade-Out|7
37|G 3|Play / Fade-Out|8
38|G# 3|Play / Fade-Out|9
39|A 3|Play / Fade-Out|10
3A|Bb 3|Play / Fade-Out|11
3B|B 3|Play / Fade-Out|12
3C|C 4|Play / Fade-Out|13
3D|C# 4|Play / Fade-Out|14
3E|D 4|Play / Fade-Out|15
3F|Eb 4|Play / Fade-Out|16
40|E 4|Play / Fade-Out|17
41|F 4|Play / Fade-Out|18
42|F# 4|Play / Fade-Out|19
43|G 4|Play / Fade-Out|20
44|G# 4|Play / Fade-Out|21
45|A 4|Play / Fade-Out|22
46|Bb 4|Play / Fade-Out|23
47|B 4|Play / Fade-Out|24

## OSC Kommandos und Nachrichten
Übersicht der OSC Kommandos und Nachrichten des Ultraschall Soundboards.

### Befehle
Die folgende Befehle können per OSC an das Soundboard gesendet werden. Der globale OSC Namensraum des Soundboards ist /ultraschall/soundboard/. Der OSC Namensraum der Player ist /ultraschall/soundboard/player/\*, wobei \* mit der Nummer des Players ersetzt wird. Um die Kompatibilität mit verschiedenen Clients zu erhöhen, werden alle OSC werte in **float** ausgewertet.

**/ultraschall/soundboard/player/*/play float (1.0)**

Mit diesem Befehl wird der Play Knopf getriggert. Dieses Kommando wird ignoriert wenn der Player sich schon im Abspiel Modus befindet.

___
**/ultraschall/soundboard/player/*/pause float (1.0)**

Dieser Befehl triggert den Pause Knopf. Dieses Kommando wird ignoriert wenn der Player sich nicht im Abspiel Modus befindet.

___
**/ultraschall/soundboard/player/*/stop float (1.0)**

Mit Stop beendet wird die Wiedergabe gestoppet. Player die bereits gespielt wurden werden durch Stop zurück auf nicht gespielt gesetzt.

___
**/ultraschall/soundboard/player/*/tigger float (0.0,1.0)**

Dieses Kommando startet einen nicht spielenden Player oder stoppt einen spielenden Player. Somit kann dieser Befehl optimal für kurze Audio Schnipsel verwendet werden, wie z.B. Applaus.

___
**/ultraschall/soundboard/player/*/ftigger float (0.0,1.0)**

Dieses Kommando startet einen nicht spielenden Player oder startet den Fade-Out eines spielenden Player.

___
**/ultraschall/soundboard/player/*/loop float (0.0,1.0)**

Dieses Kommando setzt den Loop Modus des Players. Mit 1.0 wird der Loop Modus eingeschaltet und mit 0.0 wird der Loop Modus ausgeschaltet.

___
**/ultraschall/soundboard/player/*/fadeaut float (1.0)**

Startet den Fade-Out eines laufenden Players.

___
**/ultraschall/soundboard/player/*/gain float (0.0-1.0)**

Über den Gain kann die Lautstärke des Players eingestellt werden.


### Meldungen
Die folgenden Meldungen werden vom Soundboard über OSC gesendet. Wie die bei den empfangbaren Befehlen werden alle Nachrichten im Namespace /ultraschall/soundboard/ uebertragen. Beim laden eines Soundboars werden alle Werte der Player neu gesetzt. Dadurch wird dein OSC Client immer mit den passenden Informationen zu versorgen.

**/ultraschall/soundboard/player/*/play float (0.0,1.0)**

Diese Nachricht wird gesendet wenn sich der Play Status des Players ändert. Bei 0.0 spielt der Player nicht und bei 1.0 befindet sich der Player im Play Modus.

___
**/ultraschall/soundboard/player/*/pause float (0.0,1.0)**

Wenn sich der Player im Pause Modus befindet wird hier 1.0 gesendet sonst 0.0.

___
**/ultraschall/soundboard/player/*/stop float (0.0,1.0)**

Sendet 1.0 wenn der Player gestoppt ist und 0.0 wenn der Player sich in einem beliebigen anderen Status befindet.

___
**/ultraschall/soundboard/player/*/trigger float (0.0,1.0)**

Wird der Player abgespielt wird hier 1.0 gesendet sonst 0.0.

___
**/ultraschall/soundboard/player/*/ftrigger float (0.0,1.0)**

Wird der Player abgespielt wird hier 1.0 gesendet sonst 0.0.

___
**/ultraschall/soundboard/player/*/fadeout float (0.0,1.0)**

Sobald der Fade-Out eines Players gestartet wurde wird hier 1.0 gesendet.

___
**/ultraschall/soundboard/player/*/loop float (0.0,1.0)**

Mit 1.0 wird hier ausgegeben dass der Loop Modus eingeschaltet ist.

___
**/ultraschall/soundboard/player/*/done float (0.0,1.0)**

Sobald ein Player zu ende abgespielt wurde wird hier 1.0 gesetzt. Durch drücken der Stop Taste kann dieser Wert wieder auf 0.0 gesetzt werden.

___
**/ultraschall/soundboard/player/*/progress float (0.0-1.0)**

Gibt den fortschritt des Players, im bereich von 0.0-1.0 an.

___
**/ultraschall/soundboard/player/*/title string**

Hier wird beim laden eines Soundboards der Dateiname des Players übertragen.

___
**/ultraschall/soundboard/player/*/time string**

Dieser Wert enthält den fortschritt des Players als String im Format HH:MM:SS.

___
**/ultraschall/soundboard/player/*/remaining string**

Dieser Wert enthält den verbleibende Zeit des Players als String im Format -HH:MM:SS.

___
**/ultraschall/soundboard/player/*/gain float (0.0-1.0)**

Gibt die aktuelle Lautstärke des Players an. Bei einem Fade-Out die aktuelle Fade-Out Lautstärke ausgegeben. Nach einem Fade-Out wird wieder die ausgangs Lautstärke übertragen.
