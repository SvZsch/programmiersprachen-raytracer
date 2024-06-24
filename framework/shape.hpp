//Aufgabe 5.1
// shape

#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
public:
    virtual ~Shape() = default;

    // Rein virtuelle Methoden (pure virtual methods)
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

#endif // SHAPE_HPP