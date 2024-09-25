#include <iostream>   // Für die Ein- und Ausgabe über die Konsole
#include <string>     // Für die Verwendung des std::string-Datentyps für Zeichenketten
#include <cctype>     // Für isalnum(), um zu prüfen, ob ein Zeichen alphanumerisch ist

// Funktion, um ungültige Zeichen in der Zeichenkette zu finden
bool containsInvalidCharacters(const std::string& str) {
    // Schleife durch jedes Zeichen der Zeichenkette, um zu prüfen, ob ungültige Zeichen enthalten sind
    for (char c : str) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob das Zeichen alphanumerisch ist oder ein Leerzeichen
        // **Wie funktioniert er?**: Die Funktion isalnum() prüft, ob ein Zeichen ein Buchstabe oder eine Ziffer ist.
        // Leerzeichen werden zusätzlich als gültige Zeichen erlaubt.
        if (!isalnum(c) && c != ' ') {
            // **Was tut dieser Abschnitt?**: Wenn das Zeichen nicht alphanumerisch und auch kein Leerzeichen ist, wird true zurückgegeben.
            // **Wie funktioniert er?**: Sobald ein ungültiges Zeichen gefunden wird, endet die Schleife und die Funktion gibt true zurück.
            // **Warum wird er verwendet?**: Um den Benutzer darauf hinzuweisen, dass die Zeichenkette ungültige Zeichen enthält.
            return true;
        }
    }
    // **Was tut dieser Abschnitt?**: Wenn die Schleife alle Zeichen ohne ein ungültiges Zeichen durchlaufen hat, gibt die Funktion false zurück.
    // **Wie funktioniert er?**: Es wurden keine ungültigen Zeichen gefunden, daher ist die Zeichenkette gültig.
    // **Warum wird er verwendet?**: Um zu signalisieren, dass die Zeichenkette keine ungültigen Zeichen enthält.
    return false;
}

int main() {
    // Deklarieren einer Zeichenkette für die Benutzereingabe
    std::string input;

    // Aufforderung an den Benutzer, eine Zeichenkette einzugeben
    std::cout << "Geben Sie eine Zeichenkette ein: ";

    // Verwenden von std::getline, um die gesamte Benutzereingabe (inklusive Leerzeichen) als Zeichenkette einzulesen
    std::getline(std::cin, input);

    // Überprüfe, ob die Zeichenkette ungültige Zeichen enthält
    if (containsInvalidCharacters(input)) {
        // **Was tut dieser Abschnitt?**: Gibt eine Fehlermeldung aus, wenn die Zeichenkette ungültige Zeichen enthält.
        // **Wie funktioniert er?**: Wenn containsInvalidCharacters() true zurückgibt, wird eine Fehlermeldung auf der Konsole ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer zu informieren, dass die Zeichenkette ungültige Zeichen enthält.
        std::cout << "Fehler: Die eingegebene Zeichenkette enthält ungültige Zeichen." << std::endl;
    }
    else {
        // **Was tut dieser Abschnitt?**: Gibt eine Bestätigungsmeldung aus, wenn die Zeichenkette gültig ist.
        // **Wie funktioniert er?**: Wenn containsInvalidCharacters() false zurückgibt, wird die Zeichenkette als gültig anerkannt und eine entsprechende Nachricht ausgegeben.
        // **Warum wird er verwendet?**: Um den Benutzer darüber zu informieren, dass die Zeichenkette keine ungültigen Zeichen enthält.
        std::cout << "Die eingegebene Zeichenkette ist gültig." << std::endl;
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
