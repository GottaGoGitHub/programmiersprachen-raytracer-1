#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "color.hpp"
#include <glm/vec3.hpp>

struct Light {

    std::string name = "Sun";
    glm::vec3 position{0.0f, 0.0f, 0.0f};
    Color tone{0.7f, 0.7f, 0.7f }; //Candle Light
    float intensity = 10.0f;
    
};

#endif //LIGHT_HPP