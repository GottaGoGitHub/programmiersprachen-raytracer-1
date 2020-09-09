#ifndef RAY_HPP
#define RAY_HPP

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

struct Ray {
    glm::vec3 origin = { 0.0f, 0.0f, 0.0f };
    glm::vec3 direction = { 0.0f, 0.0f, -1.0f };
};

Ray transformRay(glm::mat4 const& m, Ray const& r);

#endif