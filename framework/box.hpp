//Aufgabe 5.2
//box
#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape {
public:
    //Aufgabe 5.2 - Konstruktor
    Box(const glm::vec3& min, const glm::vec3& max);
    
    //Aufgabe 5.3 - Konstruktor
    Box(const std::string& name, const std::string& color, const glm::vec3& min, const glm::vec3& max);

    double area() const override;
    double volume() const override;

    //Aufgabe 5.4
    std::ostream& print(std::ostream& os) const override;

private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif // BOX_HPP