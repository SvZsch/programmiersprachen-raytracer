//Aufgabe 5.2
// box.hpp
#ifndef BOX_HPP                                                                 // Pr�ft, ob BOX_HPP definiert ist.
#define BOX_HPP                                                                 // Definiert BOX_HPP, um Mehrfacheinschlie�ungen zu vermeiden.

#include "shape.hpp"                                                            // Inklusion der Header-Datei f�r die Shape-Basisklasse.
#include <glm/vec3.hpp>                                                         // Inklusion der GLM-Bibliothek f�r Vektoroperationen.

// Definition der Box-Klasse, die von Shape erbt.
class Box : public Shape {
public:
    //Aufgabe 5.2 - Konstruktor
    // Konstruktor, der minimale und maximale Vektoren als Parameter akzeptiert.
    Box(const glm::vec3& min, const glm::vec3& max);

    //Aufgabe 5.3 - Konstruktor
    // Konstruktor, der Name, Farbe, minimale und maximale Vektoren als Parameter akzeptiert.
    Box(const std::string& name, const std::string& color, const glm::vec3& min, const glm::vec3& max);

    double area() const override;                                               // �berschreibt die virtuelle Methode area() der Basisklasse Shape.

    double volume() const override;                                             // �berschreibt die virtuelle Methode volume() der Basisklasse Shape.

    //Aufgabe 5.5
    std::ostream& print(std::ostream& os) const override;                       // �berschreibt die virtuelle Methode print() der Basisklasse Shape.

private:
    glm::vec3 min_;                                                             // Privatmitglied f�r den minimalen Eckpunkt der Box.
    glm::vec3 max_;                                                             // Privatmitglied f�r den maximalen Eckpunkt der Box.
};

#endif // BOX_HPP // Endet die Pr�prozessor-Direktive f�r Mehrfacheinschlie�ungen.
