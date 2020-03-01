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
**/ultraschall/soundboard/player/*/fadeout float (1.0)**

Startet den Fade-Out eines laufenden Players.

___
**/ultraschall/soundboard/player/*/gain float (0.0-1.0)**

Über den Gain kann die Lautstärke des Players eingestellt werden.

___
**/ultraschall/soundboard/gain float (0.0,1.0)**

Einstellen des Master Volumes.

___
**/ultraschall/soundboard/duck/percentage float (0.0-1.0)**

Auf wieviel Prozent der Lautstärke soll das manuelle Ducking Faden.

___
**/ultraschall/soundboard/duck/enabled float (0.0,1.0)**

Ein und Ausschalten des manuellen Duckings.

___
**/ultraschall/soundboard/player/stopall float (0.0,1.0)**

Stoppt alle laufenden Einspieler.

___
**/ultraschall/soundboard/player/fadein float (0.0,1.0)**

Startet den Fade-In. 

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
