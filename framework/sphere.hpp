//Aufgabe 5.2
//sphere.hpp
#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
public:
    //Aufgabe 5.2
    Sphere(const glm::vec3& center, double radius);

    //Aufgabe 5.3
    Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius);

    double area() const override;
    double volume() const override;

    //Aufgabe 5.5
    std::ostream& print(std::ostream& os) const override;

    //Aufgabe 5.6
    //Methode zur Schnittberechnung
    HitPoint intersect(const Ray& ray) const;

private:
    glm::vec3 center_;
    double radius_;
};

#endif // SPHERE_HPP