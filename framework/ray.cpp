#include "ray.hpp"

Ray transformRay(glm::mat4 const& m, Ray const& ray) {
	glm::vec4 a{ ray.origin, 1.0f };
	glm::vec4 b{ ray.direction, 0.0f };

	Ray ray;
	ray.origin = glm::vec3{ mat * a };
	ray.direction = glm::normalize(glm::vec3{ mat * b });
	return ray;
}