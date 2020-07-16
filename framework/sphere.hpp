#ifndef SPHERE_HPP
#define SPHERE_HPP

#define _USE_MATH_DEFINES
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <math.h>

class Sphere : public Shape {
	public:
		Sphere();
		Sphere(glm::vec3 center, float radius);
		~Sphere();
		virtual float area() const override;
		virtual float volume() const override;
	private:
		glm::vec3 center_;
		float radius_;
};
#endif