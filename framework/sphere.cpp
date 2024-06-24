//Aufgabe 5.2
//sphere.cpp
#include "sphere.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Sphere::Sphere(const glm::vec3& center, double radius)
    : center_(center), radius_(radius) {}

double Sphere::area() const {
    return 4 * M_PI * radius_ * radius_;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius_, 3);
}