#include "box.hpp"

Box::Box():
	min_{0, 0, 0},
	max_{0, 0, 0}{}


Box::Box(glm::vec3 min, glm::vec3 max):
	min_{min},
	max_{max}{}


Box::~Box() {
	std::cout << "Box destructor" << std::endl;
}

float Box::volume() const {
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float volume = a * b * c;
    return volume;
}

float Box::area() const {
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float area = 2 * (a * b) + 2 * (a * c) + 2 * (b * c);
    return area;
}