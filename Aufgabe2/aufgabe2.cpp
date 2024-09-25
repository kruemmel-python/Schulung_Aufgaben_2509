#include <iostream>  // Einbinden der iostream-Bibliothek f�r Ein- und Ausgaben
#include <limits>    // Einbinden der limits-Bibliothek, um den maximalen Wert f�r Eingabegr��en zu nutzen

int main() {
    // Deklaration der Variablen, in der die Benutzereingabe gespeichert wird
    int input;

    // Ausgabeaufforderung an den Benutzer, eine ganze Zahl einzugeben
    std::cout << "Geben Sie eine ganze Zahl ein: ";
    // Eingabe der Zahl durch den Benutzer
    std::cin >> input;

    // �berpr�fen, ob die Eingabe g�ltig war (also, ob eine ganze Zahl eingegeben wurde)
    if (std::cin.fail()) {
        // Wenn die Eingabe ung�ltig ist, wird das Fehlerflag von std::cin zur�ckgesetzt
        std::cin.clear();  // Setzt den Fehlerzustand von std::cin zur�ck, sodass weitere Eingaben m�glich sind

        // Ignoriert den restlichen fehlerhaften Input bis zum Ende der Eingabezeile,
        // um sicherzustellen, dass der fehlerhafte Input entfernt wird.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Ausgabe einer Fehlermeldung, um den Benutzer dar�ber zu informieren, dass die Eingabe ung�ltig war
        std::cout << "Ung�ltige Eingabe. Bitte geben Sie eine ganze Zahl ein." << std::endl;
    }
    else {
        // Wenn die Eingabe g�ltig war, wird die eingegebene Zahl best�tigt und ausgegeben
        std::cout << "Sie haben die Zahl " << input << " eingegeben." << std::endl;
    }

    return 0;  // Beendet das Programm und gibt 0 zur�ck, um den erfolgreichen Abschluss anzuzeigen
}
