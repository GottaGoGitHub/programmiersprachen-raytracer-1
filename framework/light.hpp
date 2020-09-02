#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "color.hpp"
#include <glm/vec3.hpp>

struct Light {
    std::string name = "Default Lamp";
    glm::vec3 position{20.0f, 20.0f, 20.0f};
    Color tone{255, 147, 41}; //Candle Light
    float intensity = 10.0f;

    //Constructor ??

    
};

#endif //LIGHT_HPP