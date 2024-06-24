#include "shape.hpp"



//Aufgabe 5.3
Shape::Shape() : name_(""), color_("") {} //Standartkonstruktor um tests funktionabel zu halten

Shape::Shape(const std::string& name, const std::string& color)
    : name_(name), color_(color) {}

//Aufgabe 5.4
//print
std::ostream& Shape::print(std::ostream& os) const {
    os << "Shape: " << name_ << ", Color: " << color_;
    return os;
}
// <<-operator
std::ostream& operator<<(std::ostream& os, Shape const& s) {
    return s.print(os);
}