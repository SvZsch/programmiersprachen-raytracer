//Aufgabe 5.6
//hitpoint
#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>                                                     // Inklusion der GLM-Bibliothek f�r Vektoroperationen.
#include <string>                                                           // Inklusion der String-Bibliothek f�r Zeichenkettenoperationen.

// Definition der Struktur HitPoint zur Repr�sentation eines Schnittpunkts.
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

    // Konstruktor, der alle Mitglieder mit �bergebenen Werten initialisiert.
    HitPoint(bool h, float dist, const std::string& name, const std::string& color, const glm::vec3& point, const glm::vec3& direction)
        : hit(h),                                                           // Initialisiert hit mit dem �bergebenen Wert h.
        distance(dist),                                                     // Initialisiert distance mit dem �bergebenen Wert dist.
        object_name(name),                                                  // Initialisiert object_name mit dem �bergebenen String name.
        object_color(color),                                                // Initialisiert object_color mit dem �bergebenen String color.
        intersection_point(point),                                          // Initialisiert intersection_point mit dem �bergebenen Vektor point.
        intersection_direction(direction) {}                                // Initialisiert intersection_direction mit dem �bergebenen Vektor direction.
};

/*Folien Klassendesign
Folie 1-2: Einf�hrung und Ziele des Klassendesigns
Ziel: Klassen sollen klar definierte Verantwortlichkeiten haben und leicht verst�ndlich sein.
Prinzip: Eine Klasse sollte eine einzige Verantwortlichkeit haben und diese klar und pr�gnant erf�llen.
Folie 3: Prinzipien guten Klassendesigns
SRP (Single Responsibility Principle): Eine Klasse sollte nur eine einzige Aufgabe haben.
OCP (Open/Closed Principle): Eine Klasse sollte offen f�r Erweiterungen, aber geschlossen f�r �nderungen sein.
LSP (Liskov Substitution Principle): Objekte einer Basisklasse sollten durch Objekte einer abgeleiteten Klasse ersetzt werden k�nnen, ohne das Programm zu ver�ndern.
ISP (Interface Segregation Principle): Es ist besser, viele spezifische Schnittstellen zu haben als eine allgemeine.
DIP (Dependency Inversion Principle): Hochrangige Module sollten nicht von niedrigrangigen Modulen abh�ngen.
Folie 4: Klassenstruktur
Kapselung: Klassen sollten ihre Daten verstecken und nur �ber Methoden Zugriff gew�hren.
Abstraktion: Klassen sollten nur das Wesentliche der Daten und Methoden pr�sentieren.
Folie 5: Datenkapselung
Zugriffskontrolle: Verwendung von privaten und gesch�tzten Membern, um den direkten Zugriff zu verhindern und nur �ber Getter/Setter zu erm�glichen.
Folie 6: Verhalten und Zustand
Zustandsinformationen: Klassen sollten ihren Zustand durch Membervariablen speichern.
Verhalten: Methoden sollen das Verhalten der Klasse definieren.
Folie 7: Verwendung von DTOs
DTOs: Werden verwendet, um Daten �ber Netzwerk oder zwischen Schichten zu �bertragen.
Kriterien f�r DTOs: �ffentliche Datenfelder, keine Gesch�ftslogik.
Anwendung auf "HitPoint"
�berlegungen f�r "HitPoint" als Klasse
Verantwortlichkeit (SRP): "HitPoint" k�nnte die Verantwortung haben, Trefferpunkte zu verwalten und zu aktualisieren.
Erweiterbarkeit (OCP): Eine Klasse k�nnte leicht um zus�tzliche Funktionalit�ten erweitert werden, wie z.B. Methoden zur Berechnung von Schadensreduktion.
Zustand und Verhalten: Eine Klasse kann sowohl den Zustand (aktuelle und maximale Trefferpunkte) als auch das Verhalten (Methoden zur Aktualisierung und Validierung) kapseln.
�berlegungen f�r "HitPoint" als DTO
Daten�bertragung: Wenn "HitPoint" haupts�chlich zur �bertragung von Trefferpunktdaten zwischen verschiedenen Teilen eines Programms oder �ber ein Netzwerk dient.
Einfachheit: Einfache Datenstruktur ohne komplexe Logik, leicht zu serialisieren und zu deserialisieren.
Entscheidung
Basierend auf den Prinzipien aus den Folien und den oben genannten �berlegungen entscheide ich mich daf�r, "HitPoint" als Klasse zu modellieren. Dies erm�glicht eine klare Verantwortlichkeit und Kapselung von Zustand und Verhalten, was den Prinzipien des guten Klassendesigns entspricht.*/

#endif // HITPOINT_HPP

