#ifndef SPHERE_HPP
#define SPHERE_HPP

#define _USE_MATH_DEFINES
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <math.h>
#include <glm/gtx/intersect.hpp>

class Sphere : public Shape {
	public:
		Sphere();
		Sphere(std::string const& name, Material const& mat, glm::vec3 const& center, float radius);
		~Sphere();
		virtual float area() const override;
		virtual float volume() const override;
		virtual std::ostream& print(std::ostream& os)const override;
		virtual HitPoint intersect(Ray ray) override;
	private:
		std::string name_;
		//Color color_;
		glm::vec3 center_;
		float radius_;
};
#endif