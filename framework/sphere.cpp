#include "sphere.hpp"
#include <iostream>

Sphere::Sphere() :
	center_{0, 0, 0},
	radius_{0},
	Shape{}{}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float radius) :
	Shape{name, color},
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

std::ostream& Sphere::print(std::ostream& os) const
{
	Shape::print(os);
	return os << " Center: " << center_.x << " " << center_.y << " " << center_.z
		<< " Radius: " << radius_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, Sphere const& s) {
	return s.print(os);
}