#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgaben
#define ARRAY_LENGTH 10  // Definieren einer Konstanten für die Länge des Arrays

int main() {
    // Deklarieren eines Arrays mit einer festen Länge von ARRAY_LENGTH, initialisiert mit Nullen
    int array[ARRAY_LENGTH] = { 0 };  // Das gesamte Array wird mit dem Wert 0 initialisiert

    // Deklarieren einer Variablen für den Array-Index
    int index = 5;  // Beispielindex, der einen gültigen Wert innerhalb des Array-Bereichs hat

    // Überprüfen, ob der Index innerhalb der gültigen Grenzen des Arrays liegt
    if (index >= 0 && index < ARRAY_LENGTH) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob der Index zwischen 0 und der maximalen Array-Größe liegt
        // **Wie funktioniert er?**: Die Bedingung stellt sicher, dass der Zugriff nur erfolgt, wenn der Index gültig ist.
        // **Warum wird er verwendet?**: Um einen sicheren Zugriff auf das Array zu ermöglichen und Fehler zu vermeiden.

        array[index] = 42;  // Sicherer Zugriff auf das Array, Zuweisen des Wertes 42 an das Element mit dem gegebenen Index
        // **Was tut dieser Abschnitt?**: Der Wert 42 wird an die Position des Arrays geschrieben, die durch `index` spezifiziert wird.
        // **Wie funktioniert er?**: Wenn der Index gültig ist, wird das Array an der entsprechenden Stelle mit einem neuen Wert überschrieben.
        // **Warum wird er verwendet?**: Um zu demonstrieren, dass der Zugriff auf das Array sicher ist, wenn der Index gültig ist.

    }
    else {
        // **Was tut dieser Abschnitt?**: Wenn der Index außerhalb der gültigen Grenzen liegt, wird eine Fehlermeldung ausgegeben
        // **Wie funktioniert er?**: Die Bedingung stellt fest, dass der Index ungültig ist, und gibt eine Nachricht über den Fehler aus.
        // **Warum wird er verwendet?**: Um den Benutzer oder Entwickler darüber zu informieren, dass ein ungültiger Array-Zugriff versucht wurde.

        std::cerr << "Ungültiger Index!" << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung auf dem Fehlerausgabestrom (std::cerr) aus.
        // **Wie funktioniert er?**: `std::cerr` wird verwendet, um Fehlermeldungen auszugeben, um Probleme von regulären Ausgaben zu trennen.
        // **Warum wird er verwendet?**: Um den Benutzer darüber zu informieren, dass der Index außerhalb der Array-Grenzen liegt.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
