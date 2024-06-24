//Aufgabe 5.1
// shape

#ifndef SHAPE_HPP
#define SHAPE_HPP

//Aufgabe 5.3
#include <string>

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

//Aufgabe 5.3
protected:
    std::string name_;
    std::string color_;
};

#endif // SHAPE_HPP