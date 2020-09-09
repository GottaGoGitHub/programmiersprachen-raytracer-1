#include "box.hpp"

Box::Box():
    Shape{},
	min_{0, 0, 0},
	max_{0, 0, 0}{}


Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) :
    Shape{name, mat},
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

std::ostream& Box::print(std::ostream& os) const
{
    Shape::print(os);
    return std::cout
        << " Min: " << min_.x << " " << min_.y << " " << min_.z
        << " Max: " << max_.x << " " << max_.y << " " << max_.z << std::endl;
}

HitPoint Box::intersect(Ray ray) {


}





std::ostream& operator<<(std::ostream& os, Box const& b) {
    return b.print(os);
}