//Aufgabe 5.2
//box.cpp
#include "box.hpp"

Box::Box(const glm::vec3& min, const glm::vec3& max)
    : min_(min), max_(max) {}

Box::Box(const std::string& name, const std::string& color, const glm::vec3& min, const glm::vec3& max)
    : Shape(name, color), min_(min), max_(max) {}


double Box::area() const {
    glm::vec3 diff = max_ - min_;
    return 2 * (diff.x * diff.y + diff.y * diff.z + diff.z * diff.x);
}

double Box::volume() const {
    glm::vec3 diff = max_ - min_;
    return diff.x * diff.y * diff.z;
}