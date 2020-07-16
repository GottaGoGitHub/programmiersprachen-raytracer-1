#include "sphere.hpp"
#include <iostream>

Sphere::Sphere():
	center_{0, 0, 0},
	radius_{0}{}

Sphere::Sphere(glm::vec3 center, float radius) :
	center_{ center },
	radius_{radius}{}

Sphere::~Sphere() {
	std::cout << "Sphere destructor" << std::endl;
}

float Sphere::volume() const {
	float volume = 1.3333 * M_PI * pow(radius_, 3);
	return volume;
}

float Sphere::area() const {
	float area = 4 * M_PI * pow(radius_, 2);
	return area;
}