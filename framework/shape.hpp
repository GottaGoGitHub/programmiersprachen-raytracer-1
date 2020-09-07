#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "color.hpp"
#include <iostream>
#include "hitpoint.hpp"
#include "ray.hpp"
#include "material.hpp"
class Shape {
	public:
		Shape();
		Shape(std::string const& name, Material const& mat);
		virtual ~Shape();
		virtual float area(void) const = 0 ;
		virtual float volume(void) const  = 0 ;
		virtual std::ostream& print(std::ostream& os) const;
		virtual HitPoint intersect(Ray ray) = 0;
	protected:
		std::string name_;
		//Color color_;
		Material material_;
};
std::ostream& operator<<(std::ostream& os, Shape const& s);
#endif
