#ifndef MATERIAL_HPP
#define MATERIAL_HPP


#include <iostream>
#include <string>
#include "color.hpp"

struct Material {

    std::string name_ = "default material";
    Color ka_{0.0f, 0.0f, 0.0f};
    Color kd_{0.0f, 0.0f, 0.0f};;
    Color ks_{0.0f, 0.0f, 0.0f};;
    float m_ = 1.0f;
};


#endif //MATERIAL_HPP