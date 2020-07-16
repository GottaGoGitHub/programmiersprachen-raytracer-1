#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("sphere") {
    glm::vec3 center{ 20, 20, 20 };
    float radius = 3;

    Sphere sphere{ center, radius };

    REQUIRE(sphere.area() == Approx(113.09734f));
    REQUIRE(sphere.volume() == Approx(113.09451f));
}

TEST_CASE("box") {
    glm::vec3 min{ 0,0,0 };
    glm::vec3 max{ 5,5,5 };

    Box box{ min, max };

    REQUIRE(box.area() == 150);
    REQUIRE(box.volume() == 125);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
