#include <iostream>   // F�r die Ein- und Ausgabe �ber die Konsole
#include <string>     // F�r die Verwendung des std::string-Datentyps f�r Zeichenketten
#include <cctype>     // F�r isalnum(), um zu pr�fen, ob ein Zeichen alphanumerisch ist

// Funktion, um ung�ltige Zeichen in der Zeichenkette zu finden
bool containsInvalidCharacters(const std::string& str) {
    // Schleife durch jedes Zeichen der Zeichenkette, um zu pr�fen, ob ung�ltige Zeichen enthalten sind
    for (char c : str) {
        // **Was tut dieser Abschnitt?**: �berpr�ft, ob das Zeichen alphanumerisch ist oder ein Leerzeichen
        // **Wie funktioniert er?**: Die Funktion isalnum() pr�ft, ob ein Zeichen ein Buchstabe oder eine Ziffer ist.
        // Leerzeichen werden zus�tzlich als g�ltige Zeichen erlaubt.
        if (!isalnum(c) && c != ' ') {
            // **Was tut dieser Abschnitt?**: Wenn das Zeichen nicht alphanumerisch und auch kein Leerzeichen ist, wird true zur�ckgegeben.
            // **Wie funktioniert er?**: Sobald ein ung�ltiges Zeichen gefunden wird, endet die Schleife und die Funktion gibt true zur�ck.
            // **Warum wird er verwendet?**: Um den Benutzer darauf hinzuweisen, dass die Zeichenkette ung�ltige Zeichen enth�lt.
            return true;
        }
    }
    // **Was tut dieser Abschnitt?**: Wenn die Schleife alle Zeichen ohne ein ung�ltiges Zeichen durchlaufen hat, gibt die Funktion false zur�ck.
    // **Wie funktioniert er?**: Es wurden keine ung�ltigen Zeichen gefunden, daher ist die Zeichenkette g�ltig.
    // **Warum wird er verwendet?**: Um zu signalisieren, dass die Zeichenkette keine ung�ltigen Zeichen enth�lt.
    return false;
}

int main() {
    // Deklarieren einer Zeichenkette f�r die Benutzereingabe
    std::string input;

    // Aufforderung an den Benutzer, eine Zeichenkette einzugeben
    std::cout << "Geben Sie eine Zeichenkette ein: ";

    // Verwenden von std::getline, um die gesamte Benutzereingabe (inklusive Leerzeichen) als Zeichenkette einzulesen
    std::getline(std::cin, input);

    // �berpr�fe, ob die Zeichenkette ung�ltige Zeichen enth�lt
    if (containsInvalidCharacters(input)) {
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Zeichenkette ung�ltige Zeichen enth�lt.
        // **Wie funktioniert er?**: Wenn containsInvalidCharacters() true zur�ckgibt, wird eine Fehlermeldung auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die Zeichenkette ung�ltige Zeichen enth�lt.
        std::cout << "Fehler: Die eingegebene Zeichenkette enth�lt ung�ltige Zeichen." << std::endl;
    }
    else {
        // **Was tut dieser Abschnitt?**: Gibt eine Best�tigungsmeldung aus, wenn die Zeichenkette g�ltig ist.
        // **Wie funktioniert er?**: Wenn containsInvalidCharacters() false zur�ckgibt, wird die Zeichenkette als g�ltig anerkannt und eine entsprechende Nachricht ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer dar�ber zu informieren, dass die Zeichenkette keine ung�ltigen Zeichen enth�lt.
        std::cout << "Die eingegebene Zeichenkette ist g�ltig." << std::endl;
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
