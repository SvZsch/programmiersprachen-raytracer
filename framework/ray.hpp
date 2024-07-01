//Aufgabe 5.6
// ray.hpp
#ifndef RAY_HPP                                     // Pr�ft, ob RAY_HPP definiert ist.
#define RAY_HPP                                     // Definiert RAY_HPP, um Mehrfacheinschlie�ungen zu vermeiden.

#include <glm/vec3.hpp>                             // Inklusion der GLM-Bibliothek f�r Vektoroperationen.
#include <glm/glm.hpp>                              // Inklusion der GLM-Bibliothek f�r allgemeine Mathe-Funktionen.
#include <glm/gtx/intersect.hpp>                    // Inklusion der GLM-Bibliothek f�r Schnittberechnungen.

// Definition der Struktur Ray zur Repr�sentation eines Strahls.
struct Ray {
    glm::vec3 origin;                               // Ursprung des Strahls.
    glm::vec3 direction;                            // Richtung des Strahls.

    // Konstruktor, der Ursprung und Richtung des Strahls akzeptiert.
    Ray(const glm::vec3& o, const glm::vec3& d)
        : origin(o),                                // Initialisiert origin mit dem �bergebenen Wert o.
        direction(glm::normalize(d)) {}             // Initialisiert direction mit dem normalisierten Vektor d.
};

#endif // RAY_HPP // Endet die Pr�prozessor-Direktive f�r Mehrfacheinschlie�ungen.

