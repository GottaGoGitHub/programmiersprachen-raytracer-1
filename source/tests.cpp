#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "sdfloader.hpp"
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

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
/*
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
*/

TEST_CASE("intersect_ray_sphere", "[intersect]")
{
    // Ray
    glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
    // ray direction has to be normalized !
    // you can use :
    // v = glm :: normalize ( some_vector )
    glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
    // Sphere
    glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
    float sphere_radius{ 1.0f };
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin, ray_direction,
        sphere_center,
        sphere_radius * sphere_radius, // squared radius !!!
        distance);
    REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("task 5.8", "[virtual]"){
    Color red{ 255 , 0 , 0 };
    glm::vec3 position{ 0.0f, 0.0f, 0.0f };
    Sphere* s1 = new Sphere{ "sphere0" , red ,position , 1.2f};
    Shape* s2 = new Sphere{ "sphere1" , red, position , 1.2f };
    s1->print(std::cout);
    s2->print(std::cout);
    delete s1;
    delete s2;
}
/*
entfernt virtual von der Basisklasse, wird beim zweiten aufruf nur der Shape Destruktor und nicht der Sphere Destruktor verwendet
*/

TEST_CASE("testing mat", "[material]"){
    Material m;
    REQUIRE(m.name_ == "default material");
    //std::cout << *def << std::endl;
}

// TEST_CASE("sdfloader", "[sdf]"){
//     std::string filepath = "../files/scene.txt";
//     Scene scene = load(filepath);
// }

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
