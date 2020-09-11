#include "sphere.hpp"
#include <iostream>

Sphere::Sphere() :
	center_{0, 0, 0},
	radius_{0},
	Shape{}{}

Sphere::Sphere(std::string const& name, Material const& mat, glm::vec3 const& center, float radius ) :
	Shape{name, mat},
	center_{ center },
	radius_{radius}{}

Sphere::~Sphere() {
	std::cout << "Sphere destructor" << std::endl;
}

float Sphere::volume() const {
	float volume = 1.3333 * M_PI * pow(radius_, 3);
	return volume;
}

float Sphere::area() const {
	float area = 4 * M_PI * pow(radius_, 2);
	return area;
}

std::ostream& Sphere::print(std::ostream& os) const
{
	Shape::print(os);
	return os << " Center: " << center_.x << " " << center_.y << " " << center_.z
		<< " Radius: " << radius_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, Sphere const& s) {
	return s.print(os);
}

HitPoint Sphere::intersect(Ray ray) {

	//Ray ray = transformRay(world_transformation_inv_, ray_in );

	HitPoint hitpoint;
	Ray norm;
	norm.direction = glm::normalize(ray.direction);
	float distance = 0.0f;

	hitpoint.gotHit = glm::intersectRaySphere(ray.origin, norm.direction, center_, radius_ * radius_, distance);
	hitpoint.hitpoint = ray.origin + distance * ray.direction;
	hitpoint.normale = glm::normalize(hitpoint.hitpoint - center_);
	hitpoint.name = name_;
	hitpoint.distance = distance;
	hitpoint.material = material_;

	/*glm::vec4 hitpoint_transformed = world_transformation_ * glm::vec4(hitpoint.hitpoint, 1.0f);
	glm::vec4 normale_transformed = glm::transpose(world_transformation_inv_) * glm::vec4{ glm::normalize(hitpoint.normale), 0.0f };

	hitpoint.hitpoint = { hitpoint_transformed.x, hitpoint_transformed.y, hitpoint_transformed.z };
	hitpoint.normale = { normale_transformed.x, normale_transformed.y, normale_transformed.z };*/

	return hitpoint;
}