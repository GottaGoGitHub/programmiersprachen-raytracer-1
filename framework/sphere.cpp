#include "sphere.hpp"
#include <iostream>

Sphere::Sphere() :
	center_{0, 0, 0},
	radius_{0},
	Shape{}{}

Sphere::Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color) :
	center_{ center },
	radius_{radius},
	name_{ name },
	color_{ color }{}

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