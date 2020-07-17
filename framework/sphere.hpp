#ifndef SPHERE_HPP
#define SPHERE_HPP

#define _USE_MATH_DEFINES
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <math.h>

class Sphere : public Shape {
	public:
		Sphere();
		Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color);
		~Sphere();
		virtual float area() const override;
		virtual float volume() const override;
	private:
		glm::vec3 center_;
		float radius_;
		std::string name_;
		Color color_;
};
#endif