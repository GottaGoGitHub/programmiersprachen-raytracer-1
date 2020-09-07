#include "shape.hpp"

Shape::Shape():
	name_{"NULL"},
	material_{}{}

Shape::Shape(std::string const& name, Material const& mat):
	name_{name},
	material_{mat}{}

Shape::~Shape(){
	std::cout << "Shape destructor" << std::endl;
}

std::ostream& Shape::print(std::ostream& os) const {
	return os << "Name: " << name_ << " Farbe: " << "ne" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
	return s.print(os);
}