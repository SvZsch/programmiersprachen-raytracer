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
    //Aufgabe 5.3 - �berladener (Parametrisierter) Konstruktor
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
std::ostream& operator<<(std::ostream& os, Shape const& s);     //�berladen des << operators

#endif // SHAPE_HPP