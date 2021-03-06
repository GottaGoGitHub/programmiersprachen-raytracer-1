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

void Shape::translate(glm::vec3 const& direction) {

	glm::mat4 translation_matrix = glm::mat4{

		glm::vec4(1.0f, 0.0f, 0.0f, direction.x),
		glm::vec4(0.0f, 1.0f, 0.0f, direction.y),
		glm::vec4(0.0f, 0.0f, 1.0f, direction.z),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)

	};

	world_transformation_ = translation_matrix * world_transformation_;
	world_transformation_inv_ = glm::inverse(world_transformation_);

}

void Shape::scale(glm::vec3 const& direction) {

	glm::mat4 scaling_matrix = glm::mat4{

		glm::vec4(direction.x, 0.0f, 0.0f, 0.0f),
		glm::vec4(0.0f, direction.y, 0.0f, 0.0f),
		glm::vec4(0.0f, 0.0f, direction.z, 0.0f),
		glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)

	};

	world_transformation_ = scaling_matrix * world_transformation_;
	world_transformation_inv_ = glm::inverse(world_transformation_);

}

void Shape::rotate(float phi, glm::vec3 const& axis) {

	phi = phi * M_PI / 180;

}