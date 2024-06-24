#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <glm/vec3.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Testfälle für Sphere und Box
TEST_CASE("Test Sphere area and volume", "[sphere]") {
    Sphere sphere(glm::vec3(0.0, 0.0, 0.0), 5.0);
    REQUIRE(sphere.area() == Approx(4 * M_PI * 25.0));
    REQUIRE(sphere.volume() == Approx((4.0 / 3.0) * M_PI * 125.0));
}

TEST_CASE("Test Box area and volume", "[box]") {
    Box box(glm::vec3(0.0, 0.0, 0.0), glm::vec3(2.0, 3.0, 4.0));
    REQUIRE(box.area() == Approx(2 * (2.0 * 3.0 + 3.0 * 4.0 + 4.0 * 2.0)));
    REQUIRE(box.volume() == Approx(2.0 * 3.0 * 4.0));
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}