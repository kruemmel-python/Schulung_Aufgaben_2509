#include <iostream>   // Für die Ein- und Ausgabe über die Konsole
#include <string>     // Für die Verwendung von std::string für Zeichenkettenoperationen
#include <vector>     // Für die Verwendung von std::vector, um Zeichenpaarungen zu speichern

const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Definiert das Alphabet als Konstante

// Klasse für die Tastatur (Keyboard)
class Keyboard {
public:
    // Methode zur Umwandlung eines Buchstabens in ein Signal (Index im Alphabet)
    int forward(char letter) {
        // **Was tut dieser Abschnitt?**: Überprüft, ob das Zeichen ein gültiger Buchstabe ist.
        // **Wie funktioniert er?**: Wenn der Buchstabe außerhalb des Bereichs A–Z liegt, wird eine Fehlermeldung ausgegeben und -1 zurückgegeben.
        // **Warum wird er verwendet?**: Um sicherzustellen, dass nur gültige Buchstaben verarbeitet werden.
        if (letter < 'A' || letter > 'Z') {
            std::cerr << "Ungültiges Zeichen: " << letter << std::endl;
            return -1;  // Fehlercode, falls ungültiges Zeichen gefunden wird
        }
        // **Was tut dieser Abschnitt?**: Wandelt den Buchstaben in einen numerischen Index um.
        // **Wie funktioniert er?**: Die Methode find() sucht nach dem Index des Buchstabens im Alphabet und gibt diesen Index zurück.
        // **Warum wird er verwendet?**: Der numerische Index wird verwendet, um den Buchstaben in den nachfolgenden Prozessen der Enigma-Maschine weiterzuleiten.
        return ALPHABET.find(letter);
    }

    // Methode zur Umwandlung eines Signals (Index) in einen Buchstaben
    char backward(int signal) {
        // **Was tut dieser Abschnitt?**: Wandelt einen Index (Signal) zurück in einen Buchstaben.
        // **Wie funktioniert er?**: Der Index wird genutzt, um den Buchstaben an der entsprechenden Position im Alphabet zu finden und zurückzugeben.
        // **Warum wird er verwendet?**: Um das Signal am Ende des Enigma-Prozesses wieder in einen lesbaren Buchstaben zu verwandeln.
        return ALPHABET[signal];
    }
};

// Klasse für das Steckbrett (Plugboard)
class Plugboard {
private:
    std::string left = ALPHABET;  // Linke Seite des Plugboards, standardmäßig das Alphabet
    std::string right = ALPHABET; // Rechte Seite des Plugboards, standardmäßig das Alphabet

public:
    // Konstruktor zum Erstellen von Zeichenpaarungen im Plugboard
    Plugboard(const std::vector<std::pair<char, char>>& pairs) {
        // **Was tut dieser Abschnitt?**: Initialisiert das Plugboard mit einem Satz von Zeichenpaarungen.
        // **Wie funktioniert er?**: Der Konstruktor nimmt eine Liste von Buchstabenpaaren und vertauscht die Buchstaben in den Paaren auf der linken Seite des Plugboards.
        // **Warum wird er verwendet?**: Das Plugboard simuliert die physische Verdrahtung der Enigma-Maschine, bei der bestimmte Buchstaben vertauscht werden.
        for (const auto& pair : pairs) {
            char A = pair.first;
            char B = pair.second;
            size_t pos_A = left.find(A);  // Findet die Position von A in der linken Seite
            size_t pos_B = left.find(B);  // Findet die Position von B in der linken Seite

            // **Was tut dieser Abschnitt?**: Tauscht die Buchstaben A und B auf der linken Seite des Plugboards.
            // **Wie funktioniert er?**: Durch das Tauschen der Buchstabenpositionen im String left wird die Verdrahtung des Plugboards simuliert.
            // **Warum wird er verwendet?**: Um den Austausch von Buchstaben gemäß der Plugboard-Konfiguration zu ermöglichen.
            left[pos_A] = B;
            left[pos_B] = A;
        }
    }

    // Methode zur Umwandlung eines Signals auf dem Weg "vorwärts" durch das Plugboard
    int forward(int signal) {
        // **Was tut dieser Abschnitt?**: Findet das zugehörige Signal, wenn der Strom durch das Plugboard geht.
        // **Wie funktioniert er?**: Der Buchstabe an der Signalposition auf der rechten Seite wird gesucht, und dessen Position auf der linken Seite wird zurückgegeben.
        // **Warum wird er verwendet?**: Um das Signal durch das Plugboard gemäß der eingestellten Buchstabenpaarungen zu leiten.
        char letter = right[signal];    // Holt den Buchstaben an der Signalposition auf der rechten Seite
        return left.find(letter);       // Findet das Signal auf der linken Seite, das dem Buchstaben entspricht
    }

    // Methode zur Umwandlung eines Signals auf dem Weg "rückwärts" durch das Plugboard
    int backward(int signal) {
        // **Was tut dieser Abschnitt?**: Findet das zugehörige Signal auf dem Rückweg durch das Plugboard.
        // **Wie funktioniert er?**: Der Buchstabe an der Signalposition auf der linken Seite wird gesucht, und dessen Position auf der rechten Seite wird zurückgegeben.
        // **Warum wird er verwendet?**: Um das Signal zurück durch das Plugboard zu leiten.
        char letter = left[signal];     // Holt den Buchstaben an der Signalposition auf der linken Seite
        return right.find(letter);      // Findet das Signal auf der rechten Seite, das dem Buchstaben entspricht
    }
};

// Klasse für den Rotor
class Rotor {
private:
    std::string left = ALPHABET;  // Linke Seite des Rotors (statisch)
    std::string right;            // Rechte Seite des Rotors (verkabelt)
    char notch;                   // Notch-Position, bei der der nächste Rotor rotiert

public:
    // Konstruktor, um den Rotor mit Verdrahtung und Notch zu initialisieren
    Rotor(const std::string& wiring, char notch) : right(wiring), notch(notch) {
        // **Was tut dieser Abschnitt?**: Initialisiert den Rotor mit einem festen Verdrahtungsmuster (Wiring) und einer Kerbe (Notch).
        // **Wie funktioniert er?**: Das Verdrahtungsmuster (right) wird gespeichert und die Kerbe (notch) wird gesetzt.
        // **Warum wird er verwendet?**: Die Rotoren simulieren die Umwandlung von Signalen in der Enigma-Maschine und drehen sich bei jeder Eingabe weiter.
    }

    // Methode zur Umwandlung eines Signals "vorwärts" durch den Rotor
    int forward(int signal) {
        // **Was tut dieser Abschnitt?**: Leitet das Signal durch den Rotor auf dem Weg "vorwärts".
        // **Wie funktioniert er?**: Der Buchstabe auf der rechten Seite des Rotors wird ermittelt, und dessen Position auf der linken Seite wird zurückgegeben.
        // **Warum wird er verwendet?**: Um das Signal gemäß der Verdrahtung des Rotors umzuleiten.
        char letter = right[signal];    // Holt den Buchstaben auf der rechten Seite des Rotors
        return left.find(letter);       // Findet das Signal auf der linken Seite
    }

    // Methode zur Umwandlung eines Signals "rückwärts" durch den Rotor
    int backward(int signal) {
        // **Was tut dieser Abschnitt?**: Leitet das Signal durch den Rotor auf dem Rückweg.
        // **Wie funktioniert er?**: Der Buchstabe auf der linken Seite des Rotors wird ermittelt, und dessen Position auf der rechten Seite wird zurückgegeben.
        // **Warum wird er verwendet?**: Um das Signal auf dem Rückweg durch den Rotor zu leiten.
        char letter = left[signal];     // Holt den Buchstaben auf der linken Seite des Rotors
        return right.find(letter);      // Findet das Signal auf der rechten Seite
    }

    // Rotiert den Rotor um eine oder mehrere Positionen
    void rotate(int n = 1, bool forward = true) {
        // **Was tut dieser Abschnitt?**: Dreht den Rotor um eine oder mehrere Positionen.
        // **Wie funktioniert er?**: Bei jeder Rotation wird das Alphabet auf der linken und rechten Seite nach vorne oder hinten geschoben.
        // **Warum wird er verwendet?**: Die Rotoren drehen sich nach jeder Eingabe und ändern damit die Signalpfade.
        for (int i = 0; i < n; ++i) {
            if (forward) {
                left = left.substr(1) + left[0];        // Rotiert das Alphabet nach vorne
                right = right.substr(1) + right[0];     // Rotiert die Verdrahtung nach vorne
            }
            else {
                left = left[25] + left.substr(0, 25);   // Rotiert das Alphabet nach hinten
                right = right[25] + right.substr(0, 25); // Rotiert die Verdrahtung nach hinten
            }
        }
    }

    // Setzt den Rotor auf eine bestimmte Position basierend auf einem Buchstaben
    void rotate_to_letter(char letter) {
        // **Was tut dieser Abschnitt?**: Dreht den Rotor auf die Position eines bestimmten Buchstabens.
        // **Wie funktioniert er?**: Der Rotor wird um so viele Positionen gedreht, wie der Buchstabe im Alphabet entfernt ist.
        // **Warum wird er verwendet?**: Dies wird verwendet, um den Rotor auf eine bestimmte Startposition zu setzen.
        int n = ALPHABET.find(letter);  // Findet den Buchstaben im Alphabet
        rotate(n);                      // Dreht den Rotor zu dieser Position
    }

    // Setzt den Ring auf eine bestimmte Einstellung
    void set_ring(int n) {
        // **Was tut dieser Abschnitt?**: Setzt die Ringstellung des Rotors.
        // **Wie funktioniert er?**: Die Ringstellung bestimmt, wie die Kontakte des Rotors mit dem Alphabet übereinstimmen. Der Rotor wird entsprechend gedreht.
        // **Warum wird er verwendet?**: Um die Ausgangsstellung des Rotors anzupassen, was Teil des Enigma-Mechanismus ist.
        rotate(n - 1, false);           // Rotiert den Rotor entsprechend der Ringstellung
        int n_notch = ALPHABET.find(notch);  // Findet die Position des Notches im Alphabet
        notch = ALPHABET[(n_notch - n + 26) % 26];  // Setzt den Notch auf die neue Position
    }

    // Getter für die Notch-Position des Rotors
    char get_notch() const {
        // **Was tut dieser Abschnitt?**: Gibt die aktuelle Position des Notches zurück.
        // **Wie funktioniert er?**: Die Methode gibt den Buchstaben zurück, an dem sich der Notch befindet.
        // **Warum wird er verwendet?**: Der Notch bestimmt, wann der nächste Rotor rotiert wird.
        return notch;
    }

    // Getter für den ersten Buchstaben auf der linken Seite des Rotors
    char get_left_first() const {
        // **Was tut dieser Abschnitt?**: Gibt den ersten Buchstaben auf der linken Seite des Rotors zurück.
        // **Wie funktioniert er?**: Die Methode gibt den Buchstaben an Position 0 im linken Alphabet des Rotors zurück.
        // **Warum wird er verwendet?**: Um die aktuelle Ausgangsposition des Rotors zu überprüfen.
        return left[0];
    }
};

// Klasse für den Reflektor
class Reflector {
private:
    std::string left = ALPHABET;  // Linke Seite des Reflektors (statisch)
    std::string right;            // Rechte Seite des Reflektors (verkabelt)

public:
    // Konstruktor, um den Reflektor mit einer Verdrahtung zu initialisieren
    Reflector(const std::string& wiring) : right(wiring) {
        // **Was tut dieser Abschnitt?**: Initialisiert den Reflektor mit einem festen Verdrahtungsmuster.
        // **Wie funktioniert er?**: Der Reflektor ist ein fester Teil der Enigma-Maschine, der das Signal umkehrt.
        // **Warum wird er verwendet?**: Der Reflektor sorgt dafür, dass das Signal durch die Rotoren zurückgesendet wird, wodurch die Umkehrung ermöglicht wird.
    }

    // Reflektiert ein Signal (dreht den Strom um)
    int reflect(int signal) {
        // **Was tut dieser Abschnitt?**: Spiegelt das Signal im Reflektor um.
        // **Wie funktioniert er?**: Der Buchstabe auf der rechten Seite des Reflektors wird geholt, und dessen Position auf der linken Seite wird zurückgegeben.
        // **Warum wird er verwendet?**: Der Reflektor sorgt dafür, dass das Signal umgekehrt wird, was der Schlüsselmechanismus der Enigma ist.
        char letter = right[signal];    // Holt den Buchstaben auf der rechten Seite
        return left.find(letter);       // Findet das Signal auf der linken Seite
    }
};

// Klasse für die Enigma-Maschine
class Enigma {
private:
    Reflector re;      // Reflektor
    Rotor r1, r2, r3;  // Drei Rotoren
    Plugboard pb;      // Steckbrett
    Keyboard kb;       // Tastatur

public:
    // Konstruktor für die Enigma-Maschine
    Enigma(const Reflector& re, const Rotor& r1, const Rotor& r2, const Rotor& r3, const Plugboard& pb, const Keyboard& kb)
        : re(re), r1(r1), r2(r2), r3(r3), pb(pb), kb(kb) {
        // **Was tut dieser Abschnitt?**: Initialisiert die Enigma-Maschine mit Reflektor, Rotoren, Plugboard und Tastatur.
        // **Wie funktioniert er?**: Der Konstruktor weist die übergebenen Objekte zu, sodass die Enigma-Maschine aus diesen Komponenten besteht.
        // **Warum wird er verwendet?**: Die Maschine benötigt all diese Komponenten, um korrekt zu funktionieren.
    }

    // Setzt die Ringstellungen der Rotoren
    void set_rings(const std::vector<int>& rings) {
        // **Was tut dieser Abschnitt?**: Setzt die Ringstellungen der drei Rotoren.
        // **Wie funktioniert er?**: Jeder Rotor wird entsprechend der übergebenen Ringposition gedreht.
        // **Warum wird er verwendet?**: Die Ringstellung bestimmt die Ausgangsposition der Rotoren und ändert damit den Signalweg.
        r1.set_ring(rings[0]);
        r2.set_ring(rings[1]);
        r3.set_ring(rings[2]);
    }

    // Setzt die Rotoren auf eine bestimmte Startposition
    void set_key(const std::string& key) {
        // **Was tut dieser Abschnitt?**: Dreht die Rotoren auf eine bestimmte Startposition.
        // **Wie funktioniert er?**: Jeder Rotor wird so oft gedreht, wie es der Position des Buchstabens im Schlüssel entspricht.
        // **Warum wird er verwendet?**: Der Schlüssel bestimmt die Anfangsstellung der Rotoren, was für die Verschlüsselung entscheidend ist.
        r1.rotate_to_letter(key[0]);
        r2.rotate_to_letter(key[1]);
        r3.rotate_to_letter(key[2]);
    }

    // Verschlüsselt oder entschlüsselt einen Buchstaben
    char encipher(char letter) {
        // **Was tut dieser Abschnitt?**: Verschlüsselt oder entschlüsselt einen Buchstaben.
        // **Wie funktioniert er?**: Der Buchstabe wird durch das Plugboard, die Rotoren und den Reflektor geleitet, wobei das Signal bei jeder Station verändert wird.
        // **Warum wird er verwendet?**: Dies ist der Hauptprozess der Enigma-Maschine, bei dem ein Buchstabe verschlüsselt oder entschlüsselt wird.

        // Rotationslogik: Überprüft, wann sich die Rotoren drehen
        // **Was tut dieser Abschnitt?**: Dreht die Rotoren entsprechend den Notch-Positionen.
        // **Wie funktioniert er?**: Die Rotoren drehen sich nach den festgelegten Regeln basierend auf den Notches.
        // **Warum wird er verwendet?**: Um den typischen Rotationsmechanismus der Enigma zu simulieren.
        if (r2.get_left_first() == r2.get_notch() && r3.get_left_first() == r3.get_notch()) {
            r1.rotate();
            r2.rotate();
            r3.rotate();
        }
        else if (r2.get_left_first() == r2.get_notch()) {
            r1.rotate();
            r2.rotate();
            r3.rotate();
        }
        else if (r3.get_left_first() == r3.get_notch()) {
            r2.rotate();
            r3.rotate();
        }
        else {
            r3.rotate();
        }

        // Signalverarbeitung: Der Buchstabe wird durch die Maschine geleitet
        int signal = kb.forward(letter);  // **Was tut dieser Abschnitt?**: Leitet das Signal von der Tastatur ins Plugboard.
        signal = pb.forward(signal);      // **Was tut dieser Abschnitt?**: Leitet das Signal durch das Plugboard.
        signal = r3.forward(signal);      // **Was tut dieser Abschnitt?**: Leitet das Signal durch Rotor 3.
        signal = r2.forward(signal);      // **Was tut dieser Abschnitt?**: Leitet das Signal durch Rotor 2.
        signal = r1.forward(signal);      // **Was tut dieser Abschnitt?**: Leitet das Signal durch Rotor 1.
        signal = re.reflect(signal);      // **Was tut dieser Abschnitt?**: Reflektiert das Signal im Reflektor.
        signal = r1.backward(signal);     // **Was tut dieser Abschnitt?**: Leitet das Signal zurück durch Rotor 1.
        signal = r2.backward(signal);     // **Was tut dieser Abschnitt?**: Leitet das Signal zurück durch Rotor 2.
        signal = r3.backward(signal);     // **Was tut dieser Abschnitt?**: Leitet das Signal zurück durch Rotor 3.
        signal = pb.backward(signal);     // **Was tut dieser Abschnitt?**: Leitet das Signal zurück durch das Plugboard.
        return kb.backward(signal);       // **Was tut dieser Abschnitt?**: Leitet das Signal zurück zur Tastatur und gibt den Buchstaben aus.
    }
};

int main() {
    // **Was tut dieser Abschnitt?**: Initialisiert die Enigma-Maschine mit allen notwendigen Komponenten.
    // **Wie funktioniert er?**: Die Enigma-Maschine wird mit Reflektor, drei Rotoren, Plugboard und Tastatur konfiguriert.
    // **Warum wird er verwendet?**: Die Hauptfunktion des Programms ist, eine Enigma-Maschine zu simulieren.
    Keyboard KB;
    Plugboard PB({ {'A', 'B'}, {'C', 'D'}, {'E', 'F'} });  // Initialisierung des Plugboards mit Buchstabenpaaren
    Rotor I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q');          // Rotor 1 mit Verdrahtung und Notch
    Rotor II("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E');         // Rotor 2
    Rotor III("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V');        // Rotor 3
    Rotor IV("ESOVPZJAYQUIRHXLNFTGKDCMWB", 'J');         // Rotor 4
    Rotor V("VZBRGITYUPSDNHLXAWMJQOFECK", 'Z');          // Rotor 5
    Reflector B("YRUHQSLDPXNGOKMIEBFZCWVJAT");           // Reflektor B

    // Erstellen der Enigma-Maschine mit spezifischer Konfiguration
    Enigma ENIGMA(B, IV, II, I, PB, KB);

    // Setzen der Ringstellungen und Schlüssel für die Rotoren
    ENIGMA.set_rings({ 5, 26, 2 });
    ENIGMA.set_key("CAT");

    // Nachricht, die verschlüsselt werden soll
    std::string message = "TESTINGTESTINGTESTINGTESTING";
    std::string cypher_text;

    // Verschlüsselt jeden Buchstaben der Nachricht
    for (char letter : message) {
        cypher_text += ENIGMA.encipher(letter);  // Verschlüsselt den Buchstaben und fügt ihn zur verschlüsselten Nachricht hinzu
    }

    // Gibt die verschlüsselte Nachricht auf der Konsole aus
    std::cout << "Verschlüsselte Nachricht: " << cypher_text << std::endl;

    return 0;  // Beendet das Programm
}
