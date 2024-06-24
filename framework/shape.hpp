//Aufgabe 5.1
// shape

#ifndef SHAPE_HPP
#define SHAPE_HPP

//Aufgabe 5.3
#include <string>

//Aufgabe 5.4
#include<iostream>

class Shape {
public:
    //Aufgabe 5.1 Standart Konstruktor
    Shape();
    //Aufgabe 5.3 - Überladener (Parametrisierter) Konstruktor
    Shape(const std::string& name, const std::string& color);
    virtual ~Shape() = default;

    // Rein virtuelle Methoden (pure virtual methods)
    virtual double area() const = 0;
    virtual double volume() const = 0;
    
    //Aufgabe 5.4
    virtual std::ostream& print(std::ostream& os) const;

//Aufgabe 5.3
protected:
    std::string name_;
    std::string color_;
};

//Aufgabe 5.4
std::ostream& operator<<(std::ostream& os, Shape const& s);     //überladen des << operators

//Aufgabe 5.5
/*Überschreiben der Methode print in den abgeleiteten Klassen

--> override stellt sicher, das Methode der Basisklasse tatsächlich überschrieben wird
--> wenn override weggelassen wird wird trotzdem kompilirt --> es wird aber nicht die Methode der Basisklasse überschrieben sondern es wird eine neue Methode in der abgeleiteten Klasse erstellt

--> Unbeabsichtigte Methodenerstellung:
Wenn override weglassen und die Methode in der abgeleiteten Klasse nicht genau wie in der Basisklasse definiert wird, wird eine neue Methode in der abgeleiteten Klasse erstellt.
Das bedeutet, dass die Methode der Basisklasse weiterhin aufgerufen wird, was zu unerwartetem Verhalten führen kann.

Fehlende Kompilierungsfehler:
Ohne override wird der Compiler keinen Fehler anzeigen, wenn die Methode in der abgeleiteten Klasse die Methode der Basisklasse nicht überschreibt. 
Dadurch können Fehler erst zur Laufzeit erkannt werden, was die Fehlersuche erschwert.

Wartungsprobleme:
Wenn die Signatur der Methode in der Basisklasse geändert wird und override in der abgeleiteten Klasse nicht verwendet wird, 
wird die Methode in der abgeleiteten Klasse nicht mehr überschrieben. Dies kann zu schwer zu findenden Fehlern führen.

Verlust von Polymorphismus:
Polymorphismus ermöglicht es, dass Methodenaufrufe zur Laufzeit auf die richtige Methode in der richtigen Klasse aufgelöst werden. 
Wenn override weggelassen wird und eine neue Methode erstellt wird, geht dieser Polymorphismus verloren, was zu falschem Verhalten führen kann.

Um die Methode print in den abgeleiteten Klassen zu überschreiben, verwenden wir das Schlüsselwort override, um sicherzustellen, 
dass die Methode tatsächlich eine Methode der Basisklasse überschreibt.Wenn das Schlüsselwort override weggelassen wird, 
kompiliert der Code trotzdem, aber wir verlieren die zusätzliche Sicherheit, die override bietet: Es verhindert, dass 
versehentlich eine neue Methode in der abgeleiteten Klasse erstellt wird, die die Methode der Basisklasse nicht überschreibt.
Erklärung des override - Schlüsselworts

Das override - Schlüsselwort in C++ dient dazu, dem Compiler explizit mitzuteilen, dass eine Methode eine virtuelle Methode der 
Basisklasse überschreibt.Wenn eine Methode mit override deklariert wird und keine passende virtuelle Methode in der Basisklasse 
vorhanden ist, gibt der Compiler einen Fehler aus.Dies hilft, Fehler zu vermeiden, die durch Tippfehler oder falsche 
Methodensignaturen verursacht werden könnten.

Wenn override weggelassen wird, würde der Compiler keine solche Überprüfung durchführen.Falls die Methode nicht korrekt 
überschrieben wurde(z.B.aufgrund eines Tippfehlers oder falscher Parameterliste), würde der Compiler die Methode als 
neue Methode der abgeleiteten Klasse betrachten, anstatt eine Fehlermeldung auszugeben.*/

#endif // SHAPE_HPP