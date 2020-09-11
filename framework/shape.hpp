#ifndef SHAPE_HPP
#define SHAPE_HPP

#define _USE_MATH_DEFINES
#include "color.hpp"
#include <iostream>
#include "hitpoint.hpp"
#include "ray.hpp"
#include "material.hpp"
#include <glm/mat4x4.hpp>
class Shape {
	public:
		Shape();
		Shape(std::string const& name, Material const& mat);
		virtual ~Shape();
		virtual float area(void) const = 0 ;
		virtual float volume(void) const  = 0 ;
		virtual std::ostream& print(std::ostream& os) const;
		virtual HitPoint intersect(Ray ray) = 0;

		void rotate(float phi, glm::vec3 const& axis);
		void scale(glm::vec3 const& direction);
		void translate(glm::vec3 const& direction);

	protected:
		std::string name_;
		//Color color_;
		Material material_;
		glm::mat4x4 world_transformation_{};
		glm::mat4x4 world_transformation_inv_{};
};
std::ostream& operator<<(std::ostream& os, Shape const& s);
#endif