#include "shape.hpp" // Einbindung der Header-Datei für die Klasse Shape.

// Aufgabe 5.3
Shape::Shape() : name_(""), color_("") {                                        // Standardkonstruktor, der die Mitglieder name_ und color_ mit leeren Strings initialisiert.
    // Aufgabe 5.8
    std::cout << "Shape constructor called" << std::endl;                       // Gibt eine Nachricht auf der Konsole aus, wenn der Konstruktor aufgerufen wird.
} // Standardkonstruktor, um Tests funktionabel zu halten.

Shape::Shape(const std::string& name, const std::string& color)                 // Überladener (parametrisierter) Konstruktor, der Name und Farbe der Form akzeptiert.
    : name_(name), color_(color) {                                              // Initialisiert die Mitglieder name_ und color_ mit den übergebenen Werten.
    // Aufgabe 5.8
    std::cout << "Shape constructor called" << std::endl;                       // Gibt eine Nachricht auf der Konsole aus, wenn der Konstruktor aufgerufen wird.
}

// Virtueller Destruktor
Shape::~Shape() {                                                               // Destruktor, der beim Löschen eines Shape-Objekts aufgerufen wird.
    std::cout << "Shape destructor called" << std::endl;                        // Gibt eine Nachricht auf der Konsole aus, wenn der Destruktor aufgerufen wird.
}

// Aufgabe 5.4
// print
std::ostream& Shape::print(std::ostream& os) const {                            // Methode zur Ausgabe der Form-Daten.
    os << "Shape: " << name_ << ", Color: " << color_;                          // Schreibt die Form-Daten (Name und Farbe) in den Ausgabe-Stream.
    return os;                                                                  // Gibt den modifizierten Ausgabe-Stream zurück.
}

// <<-Operator
std::ostream& operator<<(std::ostream& os, Shape const& s) {                    // Überladen des << Operators für die Klasse Shape.
    return s.print(os);                                                         // Ruft die print-Methode der Shape-Klasse auf, um die Form-Daten in den Ausgabe-Stream zu schreiben.
}
