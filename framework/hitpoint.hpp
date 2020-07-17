#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>
#include <iostream>
#include "color.hpp"

struct HitPoint {

    bool gotHit;
    float distance;
    std::string name;
    Color color;
    glm::vec3 hitpoint;
    glm::vec3 direction;

};
#endif#pragma once
