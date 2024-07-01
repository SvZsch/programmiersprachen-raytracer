#include "sphere.hpp" // Einbinden der Header-Datei für die Klasse Sphere.
#include "ray.hpp" // Einbinden der Header-Datei für die Klasse Ray.
#include "hitpoint.hpp" // Einbinden der Header-Datei für die Struktur HitPoint.
#include <cmath> // Einbinden der cmath-Bibliothek für mathematische Funktionen.

#ifndef M_PI
#define M_PI 3.14159265358979323846                                                         // Definition von M_PI, falls es nicht definiert ist.
#endif

// Konstruktor der Sphere-Klasse, der Zentrum und Radius initialisiert.
Sphere::Sphere(const glm::vec3& center, double radius)
    : center_(center), radius_(radius) {                                                    // Initialisierungsliste für Zentrum und Radius.
    // Aufgabe 5.8
    std::cout << "Sphere constructor called" << std::endl;                                  // Ausgabe einer Nachricht auf der Konsole, wenn der Konstruktor aufgerufen wird.
}

// Überladener (parametrisierter) Konstruktor der Sphere-Klasse, der Name, Farbe, Zentrum und Radius initialisiert.
Sphere::Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius)
    : Shape(name, color), center_(center), radius_(radius) {                                // Initialisierungsliste für Name, Farbe, Zentrum und Radius.
    // Aufgabe 5.8
    std::cout << "Sphere constructor called" << std::endl;                                  // Ausgabe einer Nachricht auf der Konsole, wenn der Konstruktor aufgerufen wird.
}

// Destruktor der Sphere-Klasse.
Sphere::~Sphere() {
    std::cout << "Sphere destructor called" << std::endl;                                   // Ausgabe einer Nachricht auf der Konsole, wenn der Destruktor aufgerufen wird.
}

// Methode zur Berechnung der Oberfläche der Kugel.
double Sphere::area() const {
    return 4 * M_PI * radius_ * radius_;                                                    // Berechnung der Oberfläche der Kugel (4πr²).
}

// Methode zur Berechnung des Volumens der Kugel.
double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius_, 3);                                       // Berechnung des Volumens der Kugel ((4/3)πr³).
}

// Aufgabe 5.5
// Methode zur Ausgabe der Kugel-Daten.
std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);                                                                       // Aufruf der print-Methode der Basisklasse Shape.
    os << ", Center: (" << center_.x << ", " << center_.y << ", " << center_.z << "), Radius: " << radius_; // Ausgabe des Zentrums und des Radius.
    return os;                                                                              // Rückgabe des modifizierten Ausgabe-Streams.
}

// Aufgabe 5.6
// Methode zur Berechnung des Schnittpunkts zwischen einem Strahl und der Kugel.
HitPoint Sphere::intersect(const Ray& ray) const {
    glm::vec3 intersectionPosition;                                                         // Variable zur Speicherung der Schnittpunktposition.
    glm::vec3 intersectionNormal;                                                           // Variable zur Speicherung der Normalen am Schnittpunkt.
    float intersectionDistance;                                                             // Variable zur Speicherung der Schnittentfernung.

    // Verwendung der glm-Funktion zum Berechnen des Schnittpunkts zwischen dem Strahl und der Kugel.
    bool intersects = glm::intersectRaySphere(
        ray.origin, glm::normalize(ray.direction),                                          // Ursprung und Richtung des Strahls.
        center_, static_cast<float>(radius_),                                               // Zentrum und Radius der Kugel.
        intersectionPosition, intersectionNormal                                            // Ausgabeparameter für Schnittpunktposition und Normale.
    );

    if (intersects) { // Wenn ein Schnittpunkt existiert.
        // Rückgabe eines HitPoint-Objekts mit den entsprechenden Werten.
        return HitPoint(true, glm::length(intersectionPosition - ray.origin), name_, color_, intersectionPosition, ray.direction);
    }
    else { // Wenn kein Schnittpunkt existiert.
        // Rückgabe eines HitPoint-Objekts, das keinen Treffer anzeigt.
        return HitPoint(false, 0.0f, "", "", glm::vec3(0.0f), glm::vec3(0.0f));
    }
}
