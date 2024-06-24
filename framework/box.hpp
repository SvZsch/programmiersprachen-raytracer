//Aufgabe 5.2
//box
#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape {
public:
    Box(const glm::vec3& min, const glm::vec3& max);

    double area() const override;
    double volume() const override;

private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif // BOX_HPP