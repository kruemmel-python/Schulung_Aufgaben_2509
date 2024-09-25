#include <iostream>           // Einbinden der iostream-Bibliothek für Ein- und Ausgaben
#include <limits>             // Einbinden der limits-Bibliothek, um den maximalen und minimalen Wert von int zu verwenden

int main() {
    int a = 2147483647;       // Deklarieren der Variable a mit einem sehr hohen Wert (hier: maximaler Wert für int)
    int b = 2;                // Deklarieren der Variable b mit dem Wert 2

    // Überprüfen, ob ein Überlauf beim Addieren von a und b auftritt
    if (a > std::numeric_limits<int>::max() - b) {
        std::cout << "Fehler: Überlauf beim Addieren von a und b\n"; // Fehlermeldung ausgeben
        // **Was tut dieser Abschnitt?**: Prüft, ob die Addition von `a` und `b` zu einem Überlauf führen würde.
        // **Wie funktioniert er?**: Vergleicht `a` mit dem maximalen Wert von `int` minus `b`. Wenn das Ergebnis größer als dieser Wert ist, wird ein Überlauf festgestellt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass die Berechnung keinen Überlauf erzeugt, der zu undefiniertem Verhalten führen könnte.
    }
    else {
        int sum = a + b;      // Addieren von a und b und das Ergebnis in sum speichern
        // **Was tut dieser Abschnitt?**: Addiert die beiden Ganzzahlen `a` und `b`, wenn kein Überlauf festgestellt wird.
        // **Wie funktioniert er?**: Die beiden Werte werden sicher addiert und in der Variablen `sum` gespeichert.
        // **Warum wird er verwendet?**: Um die Addition nur durchzuführen, wenn sie sicher ist.

        std::cout << "Summe: " << sum << "\n"; // Summe ausgeben
        // **Was tut dieser Abschnitt?**: Gibt das Ergebnis der Addition von `a` und `b` aus.
        // **Wie funktioniert er?**: Wenn die Addition sicher durchgeführt wurde, wird das Ergebnis in der Variablen `sum` gespeichert und ausgegeben.
        // **Warum wird er verwendet?**: Um das Ergebnis der Berechnung anzuzeigen, wenn die Addition sicher war.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
