#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include <iostream>
class Box : public Shape{
	public:
		Box();
		Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max);
		~Box();
		virtual float area() const override;
		virtual float volume() const override;
		virtual std::ostream& print(std::ostream& os)const override;
	private:
		std::string name_;
		//Color color_;
		glm::vec3 min_;
		glm::vec3 max_;
};
#endif
