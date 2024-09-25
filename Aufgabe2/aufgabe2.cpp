#include <iostream>  // Einbinden der iostream-Bibliothek für Ein- und Ausgaben
#include <limits>    // Einbinden der limits-Bibliothek, um den maximalen Wert für Eingabegrößen zu nutzen

int main() {
    // Deklaration der Variablen, in der die Benutzereingabe gespeichert wird
    int input;

    // Ausgabeaufforderung an den Benutzer, eine ganze Zahl einzugeben
    std::cout << "Geben Sie eine ganze Zahl ein: ";
    // Eingabe der Zahl durch den Benutzer
    std::cin >> input;

    // Überprüfen, ob die Eingabe gültig war (also, ob eine ganze Zahl eingegeben wurde)
    if (std::cin.fail()) {
        // Wenn die Eingabe ungültig ist, wird das Fehlerflag von std::cin zurückgesetzt
        std::cin.clear();  // Setzt den Fehlerzustand von std::cin zurück, sodass weitere Eingaben möglich sind

        // Ignoriert den restlichen fehlerhaften Input bis zum Ende der Eingabezeile,
        // um sicherzustellen, dass der fehlerhafte Input entfernt wird.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Ausgabe einer Fehlermeldung, um den Benutzer darüber zu informieren, dass die Eingabe ungültig war
        std::cout << "Ungültige Eingabe. Bitte geben Sie eine ganze Zahl ein." << std::endl;
    }
    else {
        // Wenn die Eingabe gültig war, wird die eingegebene Zahl bestätigt und ausgegeben
        std::cout << "Sie haben die Zahl " << input << " eingegeben." << std::endl;
    }

    return 0;  // Beendet das Programm und gibt 0 zurück, um den erfolgreichen Abschluss anzuzeigen
}
