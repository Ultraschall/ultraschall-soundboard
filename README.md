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

Die Binaries kommen am besten unter C:\Program Files\VstPlugins

## MIDI Note Kommandos

Play / Stop: Durch drücken dieser Taste wird der Player abgespielt. Bei erneutem drücken wird dieser wieder Gestoppt.

Play / Pause: Durch drücken dieser Taste wird der Player abgespielt. Bei erneutem drücken wird dieser in den Pausemodus versetzt.

Play / Fade-Out: Durch drücken dieser Taste wird der Player abgespielt. Bei erneutem drücken wird dieser Aufgeblendet.

Hold & Play: Solange die Taste gedrückt wird der Player abgespielt.

Octave Name|MIDI Octave|MIDI Note Number|Note Name|Function|Player
-----------|-----------|----------------|---------|--------|------
--|-5|0|C|Play / Stop|1
--|-5|1|C#/Db|Play / Stop|2
--|-5|2|D|Play / Stop|3
--|-5|3|D#/Eb|Play / Stop|4
--|-5|4|E|Play / Stop|5
--|-5|5|F|Play / Stop|6
--|-5|6|F#/Gb|Play / Stop|7
--|-5|7|G|Play / Stop|8
--|-5|8|G#/Ab|Play / Stop|9
--|-5|9|A|Play / Stop|10
--|-5|10|A#/Bb|Play / Stop|11
--|-5|11|B|Play / Stop|12
--|-4|12|C|Play / Stop|13
--|-4|13|C#/Db|Play / Stop|14
--|-4|14|D|Play / Stop|15
--|-4|15|D#/Eb|Play / Stop|16
--|-4|16|E|Play / Stop|17
--|-4|17|F|Play / Stop|18
--|-4|18|F#/Gb|Play / Stop|19
--|-4|19|G|Play / Stop|20
--|-4|20|G#/Ab|Play / Stop|21
--|-4|21|A|Play / Stop|22
--|-4|22|A#/Bb|Play / Stop|23
--|-4|23|B|Play / Stop|24
--|-3|24|C|Play / Pause|1
--|-3|25|C#/Db|Play / Pause|2
--|-3|26|D|Play / Pause|3
--|-3|27|D#/Eb|Play / Pause|4
--|-3|28|E|Play / Pause|5
--|-3|29|F|Play / Pause|6
--|-3|30|F#/Gb|Play / Pause|7
Low|-3|31|G|Play / Pause|8
Low|-3|32|G#/Ab|Play / Pause|9
Low|-3|33|A|Play / Pause|10
Low|-3|34|A#/Bb|Play / Pause|11
Low|-3|35|B|Play / Pause|12
Low|-2|36|C|Play / Pause|13
Low|-2|37|C#/Db|Play / Pause|14
Low|-2|38|D|Play / Pause|15
Low|-2|39|D#/Eb|Play / Pause|16
Low|-2|40|E|Play / Pause|17
Low|-2|41|F|Play / Pause|18
Low|-2|42|F#/Gb|Play / Pause|19
Bass|-2|43|G|Play / Pause|20
Bass|-2|44|G#/Ab|Play / Pause|21
Bass|-2|45|A|Play / Pause|22
Bass|-2|46|A#/Bb|Play / Pause|23
Bass|-2|47|B|Play / Pause|24
Bass|-1|48|C|Play / Fade-Out|1
Bass|-1|49|C#/Db|Play / Fade-Out|2
Bass|-1|50|D|Play / Fade-Out|3
Bass|-1|51|D#/Eb|Play / Fade-Out|4
Bass|-1|52|E|Play / Fade-Out|5
Bass|-1|53|F|Play / Fade-Out|6
Bass|-1|54|F#/Gb|Play / Fade-Out|7
Middle|-1|55|G|Play / Fade-Out|8
Middle|-1|56|G#/Ab|Play / Fade-Out|9
Middle|-1|57|A|Play / Fade-Out|10
Middle|-1|58|A#/Bb|Play / Fade-Out|11
Middle|-1|59|B|Play / Fade-Out|12
Middle|0|60|C|Play / Fade-Out|13
Middle|0|61|C#/Db|Play / Fade-Out|14
Middle|0|62|D|Play / Fade-Out|15
Middle|0|63|D#/Eb|Play / Fade-Out|16
Middle|0|64|E|Play / Fade-Out|17
Middle|0|65|F|Play / Fade-Out|18
Treble|0|66|F#/Gb|Play / Fade-Out|19
Treble|0|67|G|Play / Fade-Out|20
Treble|0|68|G#/Ab|Play / Fade-Out|21
Treble|0|69|A|Play / Fade-Out|22
Treble|0|70|A#/Bb|Play / Fade-Out|23
Treble|0|71|B|Play / Fade-Out|24
Treble|1|72|C|Hold & Play|1
Treble|1|73|C#/Db|Hold & Play|2
Treble|1|74|D|Hold & Play|3
Treble|1|75|D#/Eb|Hold & Play|4
Treble|1|76|E|Hold & Play|5
Treble|1|77|F|Hold & Play|6
High|1|78|F#/Gb|Hold & Play|7
High|1|79|G|Hold & Play|8
High|1|80|G#/Ab|Hold & Play|9
High|1|81|A|Hold & Play|10
High|1|82|A#/Bb|Hold & Play|11
High|1|83|B|Hold & Play|12
High|2|84|C|Hold & Play|13
High|2|85|C#/Db|Hold & Play|14
High|2|86|D|Hold & Play|15
High|2|87|D#/Eb|Hold & Play|16
High|2|88|E|Hold & Play|17
High|2|89|F|Hold & Play|18
--|2|90|F#/Gb|Hold & Play|19
--|2|91|G|Hold & Play|20
--|2|92|G#/Ab|Hold & Play|21
--|2|93|A|Hold & Play|22
--|2|94|A#/Bb|Hold & Play|23
--|2|95|B|Hold & Play|24
--|3|96|C|-|
--|3|97|C#/Db|-|
--|3|98|D|-|
--|3|99|D#/Eb|-|
--|3|100|E|-|
--|3|101|F|-|
--|3|102|F#/Gb|-|
--|3|103|G|-|
--|3|104|G#/Ab|-|
--|3|105|A|-|
--|3|106|A#/Bb|-|
--|3|107|B|-|
--|4|108|C|-|
--|4|109|C#/Db|-|
--|4|110|D|-|
--|4|111|D#/Eb|-|
--|4|112|E|-|
--|4|113|F|-|
--|4|114|F#/Gb|-|
--|4|115|G|-|
--|4|116|G#/Ab|-|
--|4|117|A|-|
--|4|118|A#/Bb|-|
--|4|119|B|-|
--|5|120|C|-|
--|5|121|C#/Db|-|
--|5|122|D|-|
--|5|123|D#/Eb|-|
--|5|124|E|-|
--|5|125|F|-|
--|5|126|F#/Gb|-|
--|5|127|G|-|

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
**/ultraschall/soundboard/player/*/trigger float (0.0,1.0)**

Dieses Kommando startet einen nicht spielenden Player oder stoppt einen spielenden Player. Somit kann dieser Befehl optimal für kurze Audio Schnipsel verwendet werden, wie z.B. Applaus.

___
**/ultraschall/soundboard/player/*/ftrigger float (0.0,1.0)**

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
