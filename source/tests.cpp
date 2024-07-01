#define CATCH_CONFIG_RUNNER                                                                 // Definiert das Makro zur Konfiguration des Catch-Test-Runners.
#include <catch.hpp>                                                                        // Einbinden der Catch2-Testbibliothek.
#include "sphere.hpp"                                                                       // Einbinden der Header-Datei für die Klasse Sphere.
#include "box.hpp"                                                                          // Einbinden der Header-Datei für die Klasse Box.
#include <glm/vec3.hpp>                                                                     // Einbinden der glm-Bibliothek für Vektoren.
#include <glm/glm.hpp>                                                                      // Einbinden der glm-Bibliothek für grundlegende Mathematikfunktionen.
#include <glm/gtx/intersect.hpp>                                                            // Einbinden der glm-Bibliothek für Schnittberechnungen.

#ifndef M_PI
#define M_PI 3.14159265358979323846                                                         // Definition von M_PI, falls es nicht definiert ist.
#endif

// Testfall zur Überprüfung der Fläche und des Volumens einer Kugel.
TEST_CASE("Test Sphere area and volume", "[sphere]") {
    Sphere sphere(glm::vec3(0.0, 0.0, 0.0), 5.0);                                           // Erzeugt eine Kugel mit Zentrum (0,0,0) und Radius 5.
    REQUIRE(sphere.area() == Approx(4 * M_PI * 25.0));                                      // Überprüft, ob die berechnete Fläche ungefähr 4π*25 ist.
    REQUIRE(sphere.volume() == Approx((4.0 / 3.0) * M_PI * 125.0));                         // Überprüft, ob das berechnete Volumen ungefähr (4/3)π*125 ist.
}

// Testfall zur Überprüfung der Fläche und des Volumens einer Box.
TEST_CASE("Test Box area and volume", "[box]") {
    Box box(glm::vec3(0.0, 0.0, 0.0), glm::vec3(2.0, 3.0, 4.0));                            // Erzeugt eine Box mit den angegebenen Eckpunkten.
    REQUIRE(box.area() == Approx(2 * (2.0 * 3.0 + 3.0 * 4.0 + 4.0 * 2.0)));                 // Überprüft, ob die berechnete Fläche korrekt ist.
    REQUIRE(box.volume() == Approx(2.0 * 3.0 * 4.0));                                       // Überprüft, ob das berechnete Volumen korrekt ist.
}

// Aufgabe 5.6
// Testfall zur Überprüfung der Schnittberechnung zwischen einem Strahl und einer Kugel.
TEST_CASE("intersect_ray_sphere", "[intersect]") {
    // Strahl
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };                                               // Ursprung des Strahls.
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };                                            // Normalisierte Richtung des Strahls.

    // Kugel
    glm::vec3 sphere_center{ 0.0f, 0.0f, 5.0f };                                            // Zentrum der Kugel.
    float sphere_radius{ 1.0f };                                                            // Radius der Kugel.

    float distance = 0.0f;                                                                  // Variable zur Speicherung der Schnittentfernung.
    bool result = glm::intersectRaySphere(
        ray_origin, glm::normalize(ray_direction),                                          // Ursprung und Richtung des Strahls.
        sphere_center, sphere_radius * sphere_radius,                                       // Zentrum und quadratischer Radius der Kugel.
        distance                                                                            // Ausgabeparameter für die Schnittentfernung.
    );

    REQUIRE(result == true);                                                                // Überprüft, ob ein Schnittpunkt existiert.
    REQUIRE(distance == Approx(4.0f));                                                      // Überprüft, ob die berechnete Schnittentfernung korrekt ist.
}

// Testfall zur Überprüfung der Schnittberechnung zwischen einem Strahl und einer Kugel mittels der intersect-Methode der Sphere-Klasse.
TEST_CASE("Test Sphere intersect", "[sphere_intersect]") {
    Sphere sphere("TestSphere", "Green", glm::vec3(0.0, 0.0, 5.0), 1.0);                    // Erzeugt eine Kugel mit Namen, Farbe, Zentrum und Radius.
    Ray ray(glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));                            // Erzeugt einen Strahl mit Ursprung und Richtung.

    HitPoint hit = sphere.intersect(ray);                                                   // Berechnet den Schnittpunkt zwischen dem Strahl und der Kugel.

    REQUIRE(hit.hit == true);                                                               // Überprüft, ob ein Schnittpunkt existiert.
    REQUIRE(hit.distance == Approx(4.0f));                                                  // Überprüft, ob die berechnete Schnittentfernung korrekt ist.
    REQUIRE(hit.object_name == "TestSphere");                                               // Überprüft, ob der Objektname korrekt ist.
    REQUIRE(hit.object_color == "Green");                                                   // Überprüft, ob die Objektfarbe korrekt ist.
    REQUIRE(hit.intersection_point == glm::vec3(0.0, 0.0, 4.0));                            // Überprüft, ob der Schnittpunkt korrekt ist.
    REQUIRE(hit.intersection_direction == glm::vec3(0.0, 0.0, 1.0));                        // Überprüft, ob die Schnittrichtung korrekt ist.
}

// Aufgabe 5.8
// Testfall zur Überprüfung des virtuellen Destruktors.
TEST_CASE("virtual_destructor_test", "[virtual]") {
    glm::vec3 position{ 0.0f, 0.0f, 0.0f };                                                 // Position des Zentrums.
    glm::vec3 color{ 255, 0, 0 };                                                           // Farbe (nicht verwendet in diesem Testfall).
    
    std::cout << std::endl;
    std::cout << "Aufgabe 5.8" << std::endl;                                                // Ausgabe einer Nachricht auf der Konsole.

    Sphere* s1 = new Sphere{ "sphere0", "Red", position, 1.2f };                            // Dynamische Erstellung einer Kugel.
    
    Shape* s2 = new Sphere{ "sphere1", "Red", position, 1.2f };                             // Dynamische Erstellung einer Kugel als Shape-Zeiger.

    s1->print(std::cout);                                                                   // Aufruf der print-Methode für s1.
    std::cout << std::endl;
    s2->print(std::cout);                                                                   // Aufruf der print-Methode für s2.
    std::cout << std::endl;
    delete s1;                                                                              // Löschen von s1, ruft den Destruktor der Sphere-Klasse auf.
    delete s2;                                                                              // Löschen von s2, ruft den Destruktor der Sphere-Klasse auf (virtueller Destruktor).

    /*
    Ausgabe mit virtuel (Überschreiben)
    Aufgabe 5.8
Shape constructor called
Sphere constructor called
Shape constructor called
Sphere constructor called
Shape: sphere0, Color: Red, Center: (0, 0, 0), Radius: 1.2
Shape: sphere1, Color: Red, Center: (0, 0, 0), Radius: 1.2
Sphere destructor called
Shape destructor called
Sphere destructor called
Shape destructor called

Methoden werden von der Abgeleiteten zur Bassisklase aufgerufen


Ausgabe ohne virtuel (Überschreiben)
Aufgabe 5.8
Shape constructor called
Sphere constructor called
Shape constructor called
Sphere constructor called
Shape: sphere0, Color: Red, Center: (0, 0, 0), Radius: 1.2
Shape: sphere1, Color: Red, Center: (0, 0, 0), Radius: 1.2
Sphere destructor called
Shape destructor called
Shape destructor called

nur die Klassen spezifisch definirte Methode wird aufgerufen

*/


}

int main(int argc, char* argv[]) {
    // Aufgabe 5.5
    Box box1(glm::vec3(0.0, 0.0, 0.0), glm::vec3(1.0, 2.0, 3.0));                           // Erzeugt eine Box mit den angegebenen Eckpunkten.
    Box box2("Box1", "Red", glm::vec3(0.0, 0.0, 0.0), glm::vec3(1.0, 2.0, 3.0));            // Erzeugt eine Box mit Namen, Farbe und den angegebenen Eckpunkten.

    Sphere sphere1(glm::vec3(0.0, 0.0, 0.0), 5.0);                                          // Erzeugt eine Kugel mit Zentrum und Radius.
    Sphere sphere2("Sphere1", "Blue", glm::vec3(0.0, 0.0, 0.0), 5.0);                       // Erzeugt eine Kugel mit Namen, Farbe, Zentrum und Radius.
    std::cout << std::endl;
    std::cout << "Aufgabe 5.5" << std::endl;                                                // Ausgabe einer Nachricht auf der Konsole.
    std::cout << box1 << std::endl;                                                         // Ausgabe der Box-Daten.
    std::cout << box2 << std::endl;                                                         // Ausgabe der Box-Daten.

    std::cout << sphere1 << std::endl;                                                      // Ausgabe der Kugel-Daten.
    std::cout << sphere2 << std::endl;                                                      // Ausgabe der Kugel-Daten.
    std::cout << std::endl;
    return Catch::Session().run(argc, argv);                                                // Startet die Catch2-Tests und gibt das Ergebnis zurück.
}
