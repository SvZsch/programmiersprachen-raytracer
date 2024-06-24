//Aufgabe 5.2
//sphere.hpp
#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
public:
    Sphere(const glm::vec3& center, double radius);

    double area() const override;
    double volume() const override;

private:
    glm::vec3 center_;
    double radius_;
};

#endif // SPHERE_HPP