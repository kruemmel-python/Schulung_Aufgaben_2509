#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgabe
#include <fstream>   // Einbinden der fstream-Bibliothek f�r Dateioperationen (Lesen und Schreiben)
using namespace std; // Verwendung des Standard-Namensraums, damit std:: nicht immer n�tig ist

int main() {
    // Versuch, die Datei "nonexistent_file.txt" im Lesemodus zu �ffnen.
    ifstream inputFile("nonexistent_file.txt");
    // ifstream wird verwendet, um eine Datei im Lesemodus zu �ffnen. 
    // Der Dateiname ist "nonexistent_file.txt", was bedeutet, dass die Datei wahrscheinlich nicht existiert.

    // �berpr�fen, ob die Datei erfolgreich ge�ffnet wurde
    if (inputFile.is_open()) {
        // **Was tut dieser Abschnitt?**: �berpr�ft, ob die Datei erfolgreich ge�ffnet wurde.
        // **Wie funktioniert er?**: is_open() gibt true zur�ck, wenn die Datei erfolgreich ge�ffnet wurde.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass die Datei existiert und bereit f�r den Lesevorgang ist.

        // Erfolgreiches �ffnen der Datei, Ausgabe einer Best�tigungsmeldung
        cout << "Datei wurde erfolgreich ge�ffnet." << endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Nachricht aus, dass die Datei erfolgreich ge�ffnet wurde.
        // **Wie funktioniert er?**: Wenn die Datei existiert, wird die Meldung auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die Datei erfolgreich ge�ffnet wurde und mit ihr gearbeitet werden kann.

        // Hier k�nnten weitere Operationen mit der Datei durchgef�hrt werden, z.B. das Lesen von Daten

        // Datei schlie�en
        inputFile.close();
        // **Was tut dieser Abschnitt?**: Schlie�t die ge�ffnete Datei.
        // **Wie funktioniert er?**: Die close()-Methode wird aufgerufen, um die Datei ordnungsgem�� zu schlie�en und Ressourcen freizugeben.
        // **Warum wird er verwendet?**: Nach der Verarbeitung der Datei sollte diese geschlossen werden, um Speicher und Dateizugriff freizugeben.

    }
    else {
        // Wenn die Datei nicht ge�ffnet werden konnte, Ausgabe einer Fehlermeldung
        cout << "Fehler: Die Datei konnte nicht ge�ffnet werden." << endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Datei nicht existiert oder nicht ge�ffnet werden kann.
        // **Wie funktioniert er?**: Wenn is_open() false zur�ckgibt, wird dieser Block ausgef�hrt.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass ein Fehler beim �ffnen der Datei aufgetreten ist, z.B. weil die Datei nicht existiert.
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, was den erfolgreichen Abschluss des Programms anzeigt
}
