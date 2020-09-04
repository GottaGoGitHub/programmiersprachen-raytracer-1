#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>

struct Camera {

    glm::vec3 position{0.0f, 0.0f, 0.0f};
    float phi = 45.0f;
    glm::vec3 direction{0.0f, 0.0f, -1.0f};

};

#endif //CAMERA_HPP