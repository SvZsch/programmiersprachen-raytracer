//Aufgabe 5.2
// sphere.hpp
#ifndef SPHERE_HPP                                                  // Prüft, ob SPHERE_HPP definiert ist.
#define SPHERE_HPP                                                  // Definiert SPHERE_HPP, um Mehrfacheinschließungen zu vermeiden.

#include "shape.hpp"                                                // Einbindung der Header-Datei für die Basisklasse Shape.
#include "ray.hpp"                                                  // Einbindung der Header-Datei für die Ray-Struktur.
#include "hitpoint.hpp"                                             // Einbindung der Header-Datei für die HitPoint-Struktur.
#include <glm/vec3.hpp>                                             // Einbindung der GLM-Bibliothek für Vektoroperationen.

class Sphere : public Shape {                                       // Definition der Klasse Sphere, die von der Klasse Shape erbt.
public:
    //Aufgabe 5.2
    Sphere(const glm::vec3& center, double radius);                 // Deklariert einen Konstruktor, der Zentrum und Radius der Kugel akzeptiert.

    //Aufgabe 5.3
    Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius); // Deklariert einen Konstruktor, der Name, Farbe, Zentrum und Radius der Kugel akzeptiert.

    ~Sphere() override;                                             // Deklariert den Destruktor der Kugel, überschreibt den virtuellen Destruktor der Basisklasse.

    double area() const override;                                   // Deklariert eine Methode zur Berechnung der Oberfläche, überschreibt die rein virtuelle Methode der Basisklasse.
    double volume() const override;                                 // Deklariert eine Methode zur Berechnung des Volumens, überschreibt die rein virtuelle Methode der Basisklasse.

    //Aufgabe 5.5
    std::ostream& print(std::ostream& os) const override;           // Deklariert eine Methode zur Ausgabe der Kugel-Daten, überschreibt die virtuelle Methode der Basisklasse.

    //Aufgabe 5.6
    // Methode zur Schnittberechnung
    HitPoint intersect(const Ray& ray) const;                       // Deklariert eine Methode zur Berechnung des Schnittpunkts eines Strahls mit der Kugel.

private:
    glm::vec3 center_;                                              // Speichert das Zentrum der Kugel.
    double radius_;                                                 // Speichert den Radius der Kugel.
};

#endif
