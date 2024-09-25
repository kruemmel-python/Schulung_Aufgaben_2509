#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgabe

// Funktion zur �berpr�fung, ob ein Index innerhalb der g�ltigen Array-Grenzen liegt
bool isIndexValid(int index, int arraySize) {
    // R�ckgabe von true, wenn der Index innerhalb der Grenzen liegt (0 <= index < arraySize)
    return (index >= 0 && index < arraySize);
    // **Was tut dieser Abschnitt?**: �berpr�ft, ob der Index zwischen 0 und der Arraygr��e liegt.
    // **Wie funktioniert er?**: Vergleicht den Index mit 0 und der maximalen Arraygr��e. Wenn der Index im Bereich liegt, gibt die Funktion true zur�ck, andernfalls false.
    // **Warum wird er verwendet?**: Um sicherzustellen, dass der Benutzer nur auf g�ltige Array-Positionen zugreift.
}

int main() {
    // Deklaration eines Arrays mit 5 Elementen
    int myArray[5] = { 1, 2, 3, 4, 5 };
    // Deklaration einer Variablen, die den zu �berpr�fenden Index speichert
    int indexToCheck;

    // Aufforderung an den Benutzer, einen Index einzugeben
    std::cout << "Enter an index to check: ";
    // Einlesen des Index vom Benutzer
    std::cin >> indexToCheck;

    // �berpr�fung, ob der eingegebene Index g�ltig ist, indem die Funktion isIndexValid aufgerufen wird
    if (isIndexValid(indexToCheck, 5)) {
        // **Was tut dieser Abschnitt?**: �berpr�ft, ob der eingegebene Index g�ltig ist.
        // **Wie funktioniert er?**: Die Funktion `isIndexValid` wird mit dem Benutzerindex und der Arraygr��e aufgerufen. 
        // Wenn die Funktion true zur�ckgibt, bedeutet das, dass der Index im g�ltigen Bereich liegt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass kein ung�ltiger Arrayzugriff stattfindet.

        // Ausgabe der Best�tigung, dass der Index g�ltig ist, und des Array-Elements an dieser Stelle
        std::cout << "Index is valid. The element at index " << indexToCheck << " is: " << myArray[indexToCheck] << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt das Element des Arrays an der angegebenen Indexposition aus.
        // **Wie funktioniert er?**: Wenn der Index g�ltig ist, wird das Array-Element an der entsprechenden Position ausgegeben.
        // **Warum wird er verwendet?**: Um dem Benutzer das Element am eingegebenen Index anzuzeigen.
    }
    else {
        // Ausgabe einer Fehlermeldung, wenn der Index ung�ltig ist
        std::cout << "Index is not valid." << std::endl;
        // **Was tut dieser Abschnitt?**: Informiert den Benutzer, dass der eingegebene Index ung�ltig ist.
        // **Wie funktioniert er?**: Wenn `isIndexValid` false zur�ckgibt, wird dieser Block ausgef�hrt und die Fehlermeldung ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die eingegebene Position au�erhalb der Array-Grenzen liegt.
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
