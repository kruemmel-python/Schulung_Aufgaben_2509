#include <iostream>  // Einbinden der iostream-Bibliothek für die Ein- und Ausgabe

int main() {
    // Initialisierung eines Zeigers mit dem speziellen Wert nullptr
    int* ptr = nullptr;  // nullptr ist ein spezieller Wert, der angibt, dass der Zeiger auf nichts zeigt
    // **Was tut dieser Abschnitt?**: Deklariert und initialisiert den Zeiger `ptr` mit `nullptr`, was bedeutet, dass der Zeiger aktuell auf kein gültiges Speicherobjekt zeigt.
    // **Wie funktioniert er?**: Der Zeiger wird explizit auf `nullptr` gesetzt, um anzuzeigen, dass er keinen gültigen Speicherbereich referenziert.
    // **Warum wird er verwendet?**: Die Initialisierung mit `nullptr` ist eine bewährte Praxis, um sicherzustellen, dass ein ungenutzter Zeiger nicht auf einen unerwarteten Speicherbereich zeigt.

    // Überprüfen, ob der Zeiger null ist, bevor versucht wird, ihn zu dereferenzieren
    if (ptr == nullptr) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob der Zeiger `ptr` auf `nullptr` gesetzt ist.
        // **Wie funktioniert er?**: Der `if`-Block prüft, ob der Zeiger `ptr` den Wert `nullptr` hat. Wenn dies der Fall ist, wird der entsprechende Codeblock ausgeführt.
        // **Warum wird er verwendet?**: Es ist wichtig, sicherzustellen, dass der Zeiger auf ein gültiges Objekt zeigt, bevor er dereferenziert wird, um Abstürze zu vermeiden.

        // Ausgabe einer Nachricht, die bestätigt, dass der Zeiger null ist
        std::cout << "Der Zeiger ist null." << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Nachricht aus, um den Benutzer darauf hinzuweisen, dass der Zeiger nicht auf ein gültiges Speicherobjekt zeigt.
        // **Wie funktioniert er?**: `std::cout` gibt den Text auf der Konsole aus.
        // **Warum wird er verwendet?**: Um dem Benutzer oder Entwickler klarzumachen, dass der Zeiger `nullptr` ist und es unsicher wäre, ihn zu dereferenzieren.
    }
    else {
        // Falls der Zeiger nicht `nullptr` ist, wird er sicher dereferenziert
        // **Was tut dieser Abschnitt?**: Falls der Zeiger gültig ist (also nicht `nullptr`), wird der Wert, auf den der Zeiger zeigt, ausgegeben.
        // **Wie funktioniert er?**: Der else-Block wird nur ausgeführt, wenn der Zeiger auf ein gültiges Speicherobjekt zeigt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass der Zeiger dereferenziert wird, ohne das Programm zum Absturz zu bringen.

        std::cout << "Der Wert, auf den der Zeiger zeigt: " << *ptr << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt den Wert aus, auf den der Zeiger `ptr` zeigt.
        // **Wie funktioniert er?**: Das Dereferenzieren (`*ptr`) gibt den Wert zurück, auf den der Zeiger zeigt, und dieser Wert wird dann ausgegeben.
        // **Warum wird er verwendet?**: Wenn der Zeiger gültig ist, kann der Wert an der Speicheradresse sicher gelesen und auf der Konsole ausgegeben werden.
        // Anmerkung: In diesem Fall wird der else-Block nicht erreicht, da `ptr` auf `nullptr` zeigt, was bedeutet, dass diese Zeile nicht ausgeführt wird.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
