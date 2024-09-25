#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgabe
#include <string>    // Einbinden der string-Bibliothek, um die C++-Zeichenkettentypen zu verwenden

int main() {
    // Deklarieren der Variablen f�r die Benutzereingabe
    std::string input;
    // Definieren der maximal zul�ssigen L�nge der Zeichenkette
    const int maxLength = 10;  // Maximale L�nge der Zeichenkette ist 10 Zeichen

    // Aufforderung an den Benutzer, eine Zeichenkette einzugeben
    std::cout << "Geben Sie eine Zeichenkette ein: ";
    // Verwenden von std::getline, um die gesamte Benutzereingabe (inklusive Leerzeichen) als Zeichenkette einzulesen
    std::getline(std::cin, input);

    // �berpr�fen, ob die L�nge der Zeichenkette die maximale L�nge �berschreitet
    if (input.length() > maxLength) {
        // **Was tut dieser Abschnitt?**: Pr�ft, ob die L�nge der eingegebenen Zeichenkette gr��er als der Wert von `maxLength` ist.
        // **Wie funktioniert er?**: Die Methode `length()` gibt die Anzahl der Zeichen in der Zeichenkette zur�ck. Wenn diese Anzahl gr��er als `maxLength` ist, wird der Fehlerblock ausgef�hrt.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass die Zeichenkette innerhalb der zul�ssigen L�ngenbeschr�nkung bleibt.

        std::cout << "Fehler: Die eingegebene Zeichenkette �berschreitet die maximale L�nge von " << maxLength << " Zeichen." << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Zeichenkette zu lang ist.
        // **Wie funktioniert er?**: Wenn die Bedingung `input.length() > maxLength` wahr ist, wird dieser Block ausgef�hrt und eine Nachricht auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer dar�ber zu informieren, dass die Eingabe ung�ltig ist, da die Zeichenkette die maximale L�nge �berschreitet.
    }
    else {
        // **Was tut dieser Abschnitt?**: Wenn die Zeichenkette die zul�ssige L�nge nicht �berschreitet, wird eine Erfolgsmeldung ausgegeben.
        // **Wie funktioniert er?**: Der else-Block wird ausgef�hrt, wenn die L�nge der Zeichenkette innerhalb des zul�ssigen Bereichs liegt.
        // **Warum wird er verwendet?**: Um dem Benutzer zu best�tigen, dass die eingegebene Zeichenkette g�ltig ist.

        std::cout << "Die eingegebene Zeichenkette ist g�ltig." << std::endl;
        // **Was tut dieser Abschnitt?**: Gibt eine Erfolgsmeldung aus, dass die eingegebene Zeichenkette g�ltig ist.
        // **Wie funktioniert er?**: Dieser Block wird nur ausgef�hrt, wenn die L�nge der Zeichenkette innerhalb des erlaubten Bereichs liegt.
        // **Warum wird er verwendet?**: Um den Benutzer dar�ber zu informieren, dass die Eingabe akzeptiert wurde.
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
