#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <iostream>
class Shape {
	public:
		Shape();
		Shape(std::string const& name, Color const& color);
		virtual ~Shape();
		virtual float area(void) const = 0 ;
		virtual float volume(void) const  = 0 ;
	private:
		std::string name_;
		Color color_;

};
#endif
