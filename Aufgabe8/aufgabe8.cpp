#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgabe
#include <string>    // Einbinden der string-Bibliothek, um die C++-Zeichenkettentypen zu verwenden

int main() {
    // Deklarieren der Variablen für die Benutzereingabe
    std::string input;
    // Definieren der maximal zulässigen Länge der Zeichenkette
    const int maxLength = 10;  // Maximale Länge der Zeichenkette ist 10 Zeichen

    // Aufforderung an den Benutzer, eine Zeichenkette einzugeben
    std::cout << "Geben Sie eine Zeichenkette ein: ";
    // Verwenden von std::getline, um die gesamte Benutzereingabe (inklusive Leerzeichen) als Zeichenkette einzulesen
    std::getline(std::cin, input);

    // Überprüfen, ob die Länge der Zeichenkette die maximale Länge überschreitet
    if (input.length() > maxLength) {
        // **Was tut dieser Abschnitt?**: Prüft, ob die Länge der eingegebenen Zeichenkette größer als der Wert von `maxLength` ist.
        // **Wie funktioniert er?**: Die Methode `length()` gibt die Anzahl der Zeichen in der Zeichenkette zurück. Wenn diese Anzahl größer als `maxLength` ist, wird der Fehlerblock ausgeführt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass die Zeichenkette innerhalb der zulässigen Längenbeschränkung bleibt.

        std::cout << "Fehler: Die eingegebene Zeichenkette überschreitet die maximale Länge von " << maxLength << " Zeichen." << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Zeichenkette zu lang ist.
        // **Wie funktioniert er?**: Wenn die Bedingung `input.length() > maxLength` wahr ist, wird dieser Block ausgeführt und eine Nachricht auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer darüber zu informieren, dass die Eingabe ungültig ist, da die Zeichenkette die maximale Länge überschreitet.
    }
    else {
        // **Was tut dieser Abschnitt?**: Wenn die Zeichenkette die zulässige Länge nicht überschreitet, wird eine Erfolgsmeldung ausgegeben.
        // **Wie funktioniert er?**: Der else-Block wird ausgeführt, wenn die Länge der Zeichenkette innerhalb des zulässigen Bereichs liegt.
        // **Warum wird er verwendet?**: Um dem Benutzer zu bestätigen, dass die eingegebene Zeichenkette gültig ist.

        std::cout << "Die eingegebene Zeichenkette ist gültig." << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Erfolgsmeldung aus, dass die eingegebene Zeichenkette gültig ist.
        // **Wie funktioniert er?**: Dieser Block wird nur ausgeführt, wenn die Länge der Zeichenkette innerhalb des erlaubten Bereichs liegt.
        // **Warum wird er verwendet?**: Um den Benutzer darüber zu informieren, dass die Eingabe akzeptiert wurde.
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
