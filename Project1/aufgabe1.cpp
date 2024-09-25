#include <iostream> // Einbinden der iostream-Bibliothek f�r Ein- und Ausgabe

using namespace std; // Erm�glicht den direkten Zugriff auf Standard-C++-Funktionen ohne "std::" davor schreiben zu m�ssen

int main() {
    // Deklarieren von Variablen f�r Dividend, Divisor und das Ergebnis
    double dividend, divisor, result;

    // Ausgabeaufforderung an den Benutzer, den Dividend einzugeben
    cout << "Dividend: ";
    // Eingabe des Dividend-Wertes vom Benutzer und Speichern in der Variable 'dividend'
    cin >> dividend;

    // Ausgabeaufforderung an den Benutzer, den Divisor einzugeben
    cout << "Divisor: ";
    // Eingabe des Divisor-Wertes vom Benutzer und Speichern in der Variable 'divisor'
    cin >> divisor;

    // �berpr�fen, ob der Divisor gleich 0 ist, um eine Division durch Null zu verhindern
    if (divisor == 0) {
        // Wenn der Divisor 0 ist, wird eine Fehlermeldung ausgegeben, um dem Benutzer den Fehler mitzuteilen
        cout << "Fehler: Division durch Null ist nicht erlaubt!" << endl;
        // Anmerkung: Hier k�nnte alternativ auch ein spezieller R�ckgabewert oder eine Exception genutzt werden,
        // aber in diesem Fall wird der Benutzer einfach informiert und das Programm l�uft normal weiter.
    }
    else {
        // Wenn der Divisor nicht 0 ist, wird die Division durchgef�hrt
        result = dividend / divisor; // Ergebnis der Division wird berechnet und in der Variable 'result' gespeichert

        // Das Ergebnis der Division wird auf dem Bildschirm ausgegeben
        cout << "Ergebnis: " << result << endl; // Ausgabe des Ergebnisses

        // Anmerkung: Diese Ausgabe erfolgt nur, wenn die Division g�ltig ist, d.h. der Divisor nicht 0 war.
    }

    // R�ckgabe von 0 bedeutet, dass das Programm erfolgreich ausgef�hrt wurde
    return 0;
}
