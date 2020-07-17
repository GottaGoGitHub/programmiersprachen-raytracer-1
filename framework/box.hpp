#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include <iostream>
class Box : public Shape{
	public:
		Box();
		Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color);
		~Box();
		virtual float area() const override;
		virtual float volume() const override;
	private:
		glm::vec3 min_;
		glm::vec3 max_;
		std::string name_;
		Color color_;
};
#endif
