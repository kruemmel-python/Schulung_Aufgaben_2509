#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgabe

// Funktion zur Überprüfung, ob ein Index innerhalb der gültigen Array-Grenzen liegt
bool isIndexValid(int index, int arraySize) {
    // Rückgabe von true, wenn der Index innerhalb der Grenzen liegt (0 <= index < arraySize)
    return (index >= 0 && index < arraySize);
    // **Was tut dieser Abschnitt?**: Überprüft, ob der Index zwischen 0 und der Arraygröße liegt.
    // **Wie funktioniert er?**: Vergleicht den Index mit 0 und der maximalen Arraygröße. Wenn der Index im Bereich liegt, gibt die Funktion true zurück, andernfalls false.
    // **Warum wird er verwendet?**: Um sicherzustellen, dass der Benutzer nur auf gültige Array-Positionen zugreift.
}

int main() {
    // Deklaration eines Arrays mit 5 Elementen
    int myArray[5] = { 1, 2, 3, 4, 5 };
    // Deklaration einer Variablen, die den zu überprüfenden Index speichert
    int indexToCheck;

    // Aufforderung an den Benutzer, einen Index einzugeben
    std::cout << "Enter an index to check: ";
    // Einlesen des Index vom Benutzer
    std::cin >> indexToCheck;

    // Überprüfung, ob der eingegebene Index gültig ist, indem die Funktion isIndexValid aufgerufen wird
    if (isIndexValid(indexToCheck, 5)) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob der eingegebene Index gültig ist.
        // **Wie funktioniert er?**: Die Funktion `isIndexValid` wird mit dem Benutzerindex und der Arraygröße aufgerufen. 
        // Wenn die Funktion true zurückgibt, bedeutet das, dass der Index im gültigen Bereich liegt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass kein ungültiger Arrayzugriff stattfindet.

        // Ausgabe der Bestätigung, dass der Index gültig ist, und des Array-Elements an dieser Stelle
        std::cout << "Index is valid. The element at index " << indexToCheck << " is: " << myArray[indexToCheck] << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt das Element des Arrays an der angegebenen Indexposition aus.
        // **Wie funktioniert er?**: Wenn der Index gültig ist, wird das Array-Element an der entsprechenden Position ausgegeben.
        // **Warum wird er verwendet?**: Um dem Benutzer das Element am eingegebenen Index anzuzeigen.
    }
    else {
        // Ausgabe einer Fehlermeldung, wenn der Index ungültig ist
        std::cout << "Index is not valid." << std::endl;
        // **Was tut dieser Abschnitt?**: Informiert den Benutzer, dass der eingegebene Index ungültig ist.
        // **Wie funktioniert er?**: Wenn `isIndexValid` false zurückgibt, wird dieser Block ausgeführt und die Fehlermeldung ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die eingegebene Position außerhalb der Array-Grenzen liegt.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
