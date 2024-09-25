#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgaben
#define ARRAY_LENGTH 10  // Definieren einer Konstanten f�r die L�nge des Arrays

int main() {
    // Deklarieren eines Arrays mit einer festen L�nge von ARRAY_LENGTH, initialisiert mit Nullen
    int array[ARRAY_LENGTH] = { 0 };  // Das gesamte Array wird mit dem Wert 0 initialisiert

    // Deklarieren einer Variablen f�r den Array-Index
    int index = 5;  // Beispielindex, der einen g�ltigen Wert innerhalb des Array-Bereichs hat

    // �berpr�fen, ob der Index innerhalb der g�ltigen Grenzen des Arrays liegt
    if (index >= 0 && index < ARRAY_LENGTH) {
        // **Was tut dieser Abschnitt?**: �berpr�ft, ob der Index zwischen 0 und der maximalen Array-Gr��e liegt
        // **Wie funktioniert er?**: Die Bedingung stellt sicher, dass der Zugriff nur erfolgt, wenn der Index g�ltig ist.
        // **Warum wird er verwendet?**: Um einen sicheren Zugriff auf das Array zu erm�glichen und Fehler zu vermeiden.

        array[index] = 42;  // Sicherer Zugriff auf das Array, Zuweisen des Wertes 42 an das Element mit dem gegebenen Index
        // **Was tut dieser Abschnitt?**: Der Wert 42 wird an die Position des Arrays geschrieben, die durch `index` spezifiziert wird.
        // **Wie funktioniert er?**: Wenn der Index g�ltig ist, wird das Array an der entsprechenden Stelle mit einem neuen Wert �berschrieben.
        // **Warum wird er verwendet?**: Um zu demonstrieren, dass der Zugriff auf das Array sicher ist, wenn der Index g�ltig ist.

    }
    else {
        // **Was tut dieser Abschnitt?**: Wenn der Index au�erhalb der g�ltigen Grenzen liegt, wird eine Fehlermeldung ausgegeben
        // **Wie funktioniert er?**: Die Bedingung stellt fest, dass der Index ung�ltig ist, und gibt eine Nachricht �ber den Fehler aus.
        // **Warum wird er verwendet?**: Um den Benutzer oder Entwickler dar�ber zu informieren, dass ein ung�ltiger Array-Zugriff versucht wurde.

        std::cerr << "Ung�ltiger Index!" << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung auf dem Fehlerausgabestrom (std::cerr) aus.
        // **Wie funktioniert er?**: `std::cerr` wird verwendet, um Fehlermeldungen auszugeben, um Probleme von regul�ren Ausgaben zu trennen.
        // **Warum wird er verwendet?**: Um den Benutzer dar�ber zu informieren, dass der Index au�erhalb der Array-Grenzen liegt.
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
