//Aufgabe 5.6
//hitpoint
#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>                                                     // Inklusion der GLM-Bibliothek für Vektoroperationen.
#include <string>                                                           // Inklusion der String-Bibliothek für Zeichenkettenoperationen.

// Definition der Struktur HitPoint zur Repräsentation eines Schnittpunkts.
struct HitPoint {
    bool hit;                                                               // Gibt an, ob ein Treffer vorliegt.
    float distance;                                                         // Die Entfernung zum Schnittpunkt.
    std::string object_name;                                                // Name des Objekts, das getroffen wurde.
    std::string object_color;                                               // Farbe des Objekts, das getroffen wurde.
    glm::vec3 intersection_point;                                           // Koordinaten des Schnittpunkts.
    glm::vec3 intersection_direction;                                       // Richtung des Schnittpunkts.

    // Standardkonstruktor, der alle Mitglieder initialisiert.
    HitPoint()
        : hit(false),                                                       // Initialisiert hit mit false.
        distance(0.0f),                                                     // Initialisiert distance mit 0.0.
        object_name(""),                                                    // Initialisiert object_name mit einem leeren String.
        object_color(""),                                                   // Initialisiert object_color mit einem leeren String.
        intersection_point(0.0f),                                           // Initialisiert intersection_point mit einem Vektor (0,0,0).
        intersection_direction(0.0f) {}                                     // Initialisiert intersection_direction mit einem Vektor (0,0,0).

    // Konstruktor, der alle Mitglieder mit übergebenen Werten initialisiert.
    HitPoint(bool h, float dist, const std::string& name, const std::string& color, const glm::vec3& point, const glm::vec3& direction)
        : hit(h),                                                           // Initialisiert hit mit dem übergebenen Wert h.
        distance(dist),                                                     // Initialisiert distance mit dem übergebenen Wert dist.
        object_name(name),                                                  // Initialisiert object_name mit dem übergebenen String name.
        object_color(color),                                                // Initialisiert object_color mit dem übergebenen String color.
        intersection_point(point),                                          // Initialisiert intersection_point mit dem übergebenen Vektor point.
        intersection_direction(direction) {}                                // Initialisiert intersection_direction mit dem übergebenen Vektor direction.
};

/*Folien Klassendesign
Folie 1-2: Einführung und Ziele des Klassendesigns
Ziel: Klassen sollen klar definierte Verantwortlichkeiten haben und leicht verständlich sein.
Prinzip: Eine Klasse sollte eine einzige Verantwortlichkeit haben und diese klar und prägnant erfüllen.
Folie 3: Prinzipien guten Klassendesigns
SRP (Single Responsibility Principle): Eine Klasse sollte nur eine einzige Aufgabe haben.
OCP (Open/Closed Principle): Eine Klasse sollte offen für Erweiterungen, aber geschlossen für Änderungen sein.
LSP (Liskov Substitution Principle): Objekte einer Basisklasse sollten durch Objekte einer abgeleiteten Klasse ersetzt werden können, ohne das Programm zu verändern.
ISP (Interface Segregation Principle): Es ist besser, viele spezifische Schnittstellen zu haben als eine allgemeine.
DIP (Dependency Inversion Principle): Hochrangige Module sollten nicht von niedrigrangigen Modulen abhängen.
Folie 4: Klassenstruktur
Kapselung: Klassen sollten ihre Daten verstecken und nur über Methoden Zugriff gewähren.
Abstraktion: Klassen sollten nur das Wesentliche der Daten und Methoden präsentieren.
Folie 5: Datenkapselung
Zugriffskontrolle: Verwendung von privaten und geschützten Membern, um den direkten Zugriff zu verhindern und nur über Getter/Setter zu ermöglichen.
Folie 6: Verhalten und Zustand
Zustandsinformationen: Klassen sollten ihren Zustand durch Membervariablen speichern.
Verhalten: Methoden sollen das Verhalten der Klasse definieren.
Folie 7: Verwendung von DTOs
DTOs: Werden verwendet, um Daten über Netzwerk oder zwischen Schichten zu übertragen.
Kriterien für DTOs: Öffentliche Datenfelder, keine Geschäftslogik.
Anwendung auf "HitPoint"
Überlegungen für "HitPoint" als Klasse
Verantwortlichkeit (SRP): "HitPoint" könnte die Verantwortung haben, Trefferpunkte zu verwalten und zu aktualisieren.
Erweiterbarkeit (OCP): Eine Klasse könnte leicht um zusätzliche Funktionalitäten erweitert werden, wie z.B. Methoden zur Berechnung von Schadensreduktion.
Zustand und Verhalten: Eine Klasse kann sowohl den Zustand (aktuelle und maximale Trefferpunkte) als auch das Verhalten (Methoden zur Aktualisierung und Validierung) kapseln.
Überlegungen für "HitPoint" als DTO
Datenübertragung: Wenn "HitPoint" hauptsächlich zur Übertragung von Trefferpunktdaten zwischen verschiedenen Teilen eines Programms oder über ein Netzwerk dient.
Einfachheit: Einfache Datenstruktur ohne komplexe Logik, leicht zu serialisieren und zu deserialisieren.
Entscheidung
Basierend auf den Prinzipien aus den Folien und den oben genannten Überlegungen entscheide ich mich dafür, "HitPoint" als Klasse zu modellieren. Dies ermöglicht eine klare Verantwortlichkeit und Kapselung von Zustand und Verhalten, was den Prinzipien des guten Klassendesigns entspricht.*/

#endif // HITPOINT_HPP

