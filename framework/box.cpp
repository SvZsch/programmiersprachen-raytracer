// Einbindung der Header-Datei "box.hpp", die die Deklarationen der Box-Klasse enthält.
#include "box.hpp"

// Konstruktor der Box-Klasse, der zwei glm::vec3 Objekte (min und max) als Parameter nimmt.
Box::Box(const glm::vec3& min, const glm::vec3& max)
    : min_(min), max_(max) {}                                                                   // Initialisiert die Member-Variablen min_ und max_ mit den übergebenen Werten.

// Konstruktor der Box-Klasse, der zusätzlich den Namen und die Farbe als Zeichenketten nimmt.
Box::Box(const std::string& name, const std::string& color, const glm::vec3& min, const glm::vec3& max)
    : Shape(name, color), min_(min), max_(max) {}                                               // Ruft den Konstruktor der Basisklasse Shape auf und initialisiert min_ und max_.

// Berechnet die Oberfläche der Box.
double Box::area() const {
    glm::vec3 diff = max_ - min_;                                                                // Berechnet die Differenz zwischen max_ und min_, was die Dimensionen der Box ergibt.
    return 2 * (diff.x * diff.y + diff.y * diff.z + diff.z * diff.x);                            // Berechnet die Oberfläche der Box mit der Formel für die Fläche eines Quaders.
}

// Berechnet das Volumen der Box.
double Box::volume() const {
    glm::vec3 diff = max_ - min_;                                                               // Berechnet die Differenz zwischen max_ und min_, was die Dimensionen der Box ergibt.
    return diff.x * diff.y * diff.z;                                                            // Berechnet das Volumen der Box mit der Formel für das Volumen eines Quaders.
}

// Überschreibt die print-Methode der Shape-Klasse, um Informationen über die Box auszugeben.
std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);                                                                           // Ruft die print-Methode der Basisklasse Shape auf, um deren Informationen auszugeben.
    os << ", Min: (" << min_.x << ", " << min_.y << ", " << min_.z << "), Max: ("               // Gibt die minimalen Koordinaten der Box aus.
        << max_.x << ", " << max_.y << ", " << max_.z << ")";                                   // Gibt die maximalen Koordinaten der Box aus.
    return os;                                                                                  
}
