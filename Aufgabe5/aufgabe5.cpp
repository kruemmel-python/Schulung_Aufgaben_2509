#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgabe

int main() {
    // Versuch, ein Array von 1 Billion Ganzzahlen dynamisch im Speicher zu reservieren
    // new(std::nothrow) sorgt dafür, dass bei einem Fehler nullptr zurückgegeben wird, anstatt eine Ausnahme zu werfen.
    int* ptr = new(std::nothrow) int[100000000000];

    // Überprüfen, ob die Speicherallokation erfolgreich war
    if (ptr == nullptr) {
        // Wenn die Speicherallokation fehlschlägt (ptr == nullptr), Ausgabe einer Fehlermeldung
        std::cout << "Speicherallokation fehlgeschlagen.\n";
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn der Speicher nicht erfolgreich zugewiesen wurde.
        // **Wie funktioniert er?**: Wenn `new` nicht genügend Speicher finden kann, wird `nullptr` zurückgegeben und die Fehlermeldung wird ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer oder Entwickler darüber zu informieren, dass die Speicheranforderung zu groß war oder fehlgeschlagen ist.
    }
    else {
        // Wenn die Speicherallokation erfolgreich war, Ausgabe einer Bestätigungsmeldung
        std::cout << "Speicherallokation erfolgreich.\n";
        // **Was tut dieser Abschnitt?**: Gibt eine Erfolgsmeldung aus, wenn die Speicherallokation erfolgreich war.
        // **Wie funktioniert er?**: Wenn genügend Speicher vorhanden ist, wird das Array erfolgreich erstellt, und die Bestätigung wird ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer darüber zu informieren, dass der Speicher erfolgreich zugewiesen wurde.

        // Freigeben des zugewiesenen Speichers, um Speicherlecks zu vermeiden
        delete[] ptr;
        // **Was tut dieser Abschnitt?**: Gibt den dynamisch zugewiesenen Speicher frei, wenn er nicht mehr benötigt wird.
        // **Wie funktioniert er?**: `delete[]` gibt den Speicher zurück an das System und verhindert ein Speicherleck.
        // **Warum wird er verwendet?**: Damit der dynamisch zugewiesene Speicher nicht unnötig blockiert bleibt, was zu Speicherlecks führen könnte.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
