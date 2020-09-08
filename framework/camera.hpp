#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>

struct Camera {


    float phi = 120.0f;
    glm::vec3 position{-200.0f, 0.0f, 0.0f};
    glm::vec3 direction{0.0f, 0.0f, -1.0f};
    glm::vec3 up{ 0.0f, 1.0f, 0.0f };
};

#endif //CAMERA_HPP