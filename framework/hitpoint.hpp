//Aufgabe 5.6
//hitpoint
#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>
#include <string>

struct HitPoint {
    bool hit;
    float distance;
    std::string object_name;
    std::string object_color;
    glm::vec3 intersection_point;
    glm::vec3 intersection_direction;

    HitPoint()
        : hit(false), distance(0.0f), object_name(""), object_color(""), intersection_point(0.0f), intersection_direction(0.0f) {}

    HitPoint(bool h, float dist, const std::string& name, const std::string& color, const glm::vec3& point, const glm::vec3& direction)
        : hit(h), distance(dist), object_name(name), object_color(color), intersection_point(point), intersection_direction(direction) {}
};

#endif // HITPOINT_HPP

