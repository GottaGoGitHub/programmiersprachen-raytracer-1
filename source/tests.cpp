#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("sphere") {
    glm::vec3 center{ 20, 20, 20 };
    float radius = 3;
    std::string name{ "Eric" };
    Color color{ 1.5, 0.75, 1.2 };

    Sphere sphere{ name, color, center, radius };

    REQUIRE(sphere.area() == Approx(113.09734f));
    REQUIRE(sphere.volume() == Approx(113.09451f));

    std::cout << sphere << std::endl;
}

TEST_CASE("box") {
    glm::vec3 min{ 0,0,0 };
    glm::vec3 max{ 5,5,5 };
    std::string name{ "Kai Uwe" };
    Color color{ 1.5, 0.75, 1.2 };

    Box box{ name, color, min, max };

    REQUIRE(box.area() == 150);
    REQUIRE(box.volume() == 125);

    std::cout << box << std::endl;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
