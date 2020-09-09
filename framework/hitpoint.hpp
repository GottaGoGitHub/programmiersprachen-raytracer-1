#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <glm/vec3.hpp>
#include <iostream>
#include "color.hpp"
#include "material.hpp"

struct HitPoint {

    bool gotHit = false;
    float distance;
    std::string name;
    //Color color;
    glm::vec3 hitpoint;
    glm::vec3 direction;
    glm::vec3 normale;
    Material material{};

    bool operator<(HitPoint const& hit) const {
        return distance < distance;
    }

};
#endif
