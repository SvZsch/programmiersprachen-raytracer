//Aufgabe 5.2
//sphere.cpp
#include "sphere.hpp"
#include "ray.hpp"
#include "hitpoint.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Sphere::Sphere(const glm::vec3& center, double radius)
    : center_(center), radius_(radius) {}

//Aufgabe 5.3
Sphere::Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius)
    : Shape(name, color), center_(center), radius_(radius) {}

double Sphere::area() const {
    return 4 * M_PI * radius_ * radius_;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius_, 3);
}

//Aufgabe 5.5
std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << ", Center: (" << center_.x << ", " << center_.y << ", " << center_.z << "), Radius: " << radius_;
    return os;
}

//aufgabe 5.6
HitPoint Sphere::intersect(const Ray& ray) const {
    glm::vec3 intersectionPosition;
    glm::vec3 intersectionNormal;
    float intersectionDistance;

    bool intersects = glm::intersectRaySphere(
        ray.origin, glm::normalize(ray.direction),
        center_, static_cast<float>(radius_),
        intersectionPosition, intersectionNormal
    );

    if (intersects) {
        return HitPoint(true, glm::length(intersectionPosition - ray.origin), name_, color_, intersectionPosition, ray.direction);
    }
    else {
        return HitPoint(false, 0.0f, "", "", glm::vec3(0.0f), glm::vec3(0.0f));
    }
}