#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgabe

int main() {
    // Versuch, ein Array von 1 Billion Ganzzahlen dynamisch im Speicher zu reservieren
    // new(std::nothrow) sorgt daf�r, dass bei einem Fehler nullptr zur�ckgegeben wird, anstatt eine Ausnahme zu werfen.
    int* ptr = new(std::nothrow) int[100000000000];

    // �berpr�fen, ob die Speicherallokation erfolgreich war
    if (ptr == nullptr) {
        // Wenn die Speicherallokation fehlschl�gt (ptr == nullptr), Ausgabe einer Fehlermeldung
        std::cout << "Speicherallokation fehlgeschlagen.\n";
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn der Speicher nicht erfolgreich zugewiesen wurde.
        // **Wie funktioniert er?**: Wenn `new` nicht gen�gend Speicher finden kann, wird `nullptr` zur�ckgegeben und die Fehlermeldung wird ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer oder Entwickler dar�ber zu informieren, dass die Speicheranforderung zu gro� war oder fehlgeschlagen ist.
    }
    else {
        // Wenn die Speicherallokation erfolgreich war, Ausgabe einer Best�tigungsmeldung
        std::cout << "Speicherallokation erfolgreich.\n";
        // **Was tut dieser Abschnitt?**: Gibt eine Erfolgsmeldung aus, wenn die Speicherallokation erfolgreich war.
        // **Wie funktioniert er?**: Wenn gen�gend Speicher vorhanden ist, wird das Array erfolgreich erstellt, und die Best�tigung wird ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer dar�ber zu informieren, dass der Speicher erfolgreich zugewiesen wurde.

        // Freigeben des zugewiesenen Speichers, um Speicherlecks zu vermeiden
        delete[] ptr;
        // **Was tut dieser Abschnitt?**: Gibt den dynamisch zugewiesenen Speicher frei, wenn er nicht mehr ben�tigt wird.
        // **Wie funktioniert er?**: `delete[]` gibt den Speicher zur�ck an das System und verhindert ein Speicherleck.
        // **Warum wird er verwendet?**: Damit der dynamisch zugewiesene Speicher nicht unn�tig blockiert bleibt, was zu Speicherlecks f�hren k�nnte.
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
