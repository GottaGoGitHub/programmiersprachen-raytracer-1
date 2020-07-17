#include "shape.hpp"

Shape::Shape():
	name_{"NULL"},
	color_{}{}

Shape::Shape(std::string const& name, Color const& color):
	name_{name},
	color_{color}{}

Shape::~Shape(){
	std::cout << "Shape destructor" << std::endl;
}