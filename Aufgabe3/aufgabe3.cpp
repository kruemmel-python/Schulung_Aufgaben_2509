#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgabe
#include <fstream>   // Einbinden der fstream-Bibliothek für Dateioperationen (Lesen und Schreiben)
using namespace std; // Verwendung des Standard-Namensraums, damit std:: nicht immer nötig ist

int main() {
    // Versuch, die Datei "nonexistent_file.txt" im Lesemodus zu öffnen.
    ifstream inputFile("nonexistent_file.txt");
    // ifstream wird verwendet, um eine Datei im Lesemodus zu öffnen. 
    // Der Dateiname ist "nonexistent_file.txt", was bedeutet, dass die Datei wahrscheinlich nicht existiert.

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (inputFile.is_open()) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob die Datei erfolgreich geöffnet wurde.
        // **Wie funktioniert er?**: is_open() gibt true zurück, wenn die Datei erfolgreich geöffnet wurde.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass die Datei existiert und bereit für den Lesevorgang ist.

        // Erfolgreiches Öffnen der Datei, Ausgabe einer Bestätigungsmeldung
        cout << "Datei wurde erfolgreich geöffnet." << endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Nachricht aus, dass die Datei erfolgreich geöffnet wurde.
        // **Wie funktioniert er?**: Wenn die Datei existiert, wird die Meldung auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die Datei erfolgreich geöffnet wurde und mit ihr gearbeitet werden kann.

        // Hier könnten weitere Operationen mit der Datei durchgeführt werden, z.B. das Lesen von Daten

        // Datei schließen
        inputFile.close();
        // **Was tut dieser Abschnitt?**: Schließt die geöffnete Datei.
        // **Wie funktioniert er?**: Die close()-Methode wird aufgerufen, um die Datei ordnungsgemäß zu schließen und Ressourcen freizugeben.
        // **Warum wird er verwendet?**: Nach der Verarbeitung der Datei sollte diese geschlossen werden, um Speicher und Dateizugriff freizugeben.

    }
    else {
        // Wenn die Datei nicht geöffnet werden konnte, Ausgabe einer Fehlermeldung
        cout << "Fehler: Die Datei konnte nicht geöffnet werden." << endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Datei nicht existiert oder nicht geöffnet werden kann.
        // **Wie funktioniert er?**: Wenn is_open() false zurückgibt, wird dieser Block ausgeführt.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass ein Fehler beim Öffnen der Datei aufgetreten ist, z.B. weil die Datei nicht existiert.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, was den erfolgreichen Abschluss des Programms anzeigt
}
