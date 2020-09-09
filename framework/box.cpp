#include "box.hpp"

Box::Box():
    Shape{},
	min_{0, 0, 0},
	max_{0, 0, 0}{}


Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) :
    Shape{name, mat},
	min_{min},
	max_{max}{}


Box::~Box() {
	std::cout << "Box destructor" << std::endl;
}

float Box::volume() const {
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float volume = a * b * c;
    return volume;
}

float Box::area() const {
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float area = 2 * (a * b) + 2 * (a * c) + 2 * (b * c);
    return area;
}

std::ostream& Box::print(std::ostream& os) const
{
    Shape::print(os);
    return std::cout
        << " Min: " << min_.x << " " << min_.y << " " << min_.z
        << " Max: " << max_.x << " " << max_.y << " " << max_.z << std::endl;
}

HitPoint Box::intersect(Ray ray) {

    HitPoint hit;
    Ray norm;
    norm.direction = glm::normalize(ray.direction);

    float minimum = -INFINITY;
    float maximum = INFINITY;

    float t1 = (min_.x - ray.origin.x) / ray.direction.x;
    float t2 = (max_.x - ray.origin.x) / ray.direction.x;

    minimum = std::max(minimum, std::min(t1, t2));
    maximum = std::min(maximum, std::max(t1, t2));

    t1 = (min_.y - ray.origin.y) / ray.direction.y;
    t2 = (max_.y - ray.origin.y) / ray.direction.y;

    minimum = std::max(minimum, std::min(t1, t2));
    maximum = std::min(maximum, std::max(t1, t2));

    t1 = (min_.z - ray.origin.z) / ray.direction.z;
    t2 = (max_.z - ray.origin.z) / ray.direction.z;

    minimum = std::max(minimum, std::min(t1, t2));
    maximum = std::min(maximum, std::max(t1, t2));

    if (maximum > std::max(0.0f, minimum)) {

        hit.distance = sqrt(minimum * minimum*(
            ray.direction.x * ray.direction.x +
            ray.direction.y * ray.direction.y +
            ray.direction.z * ray.direction.z));

        hit.hitpoint = ray.origin + ray.direction * hit.distance;
        hit.gotHit = true;
        hit.material = material_;
        hit.name = name_;
        hit.normale = calc_normal(hit);
        hit.direction = glm::normalize(ray.direction);
        
    }

    return hit;

}


glm::vec3 Box::calc_normal(HitPoint const& hit) {
    auto surface_pt = hit.hitpoint;
    if (surface_pt.x == Approx(min_.x))
    {
        return glm::vec3{ -1.0,0.0,0.0 };
    }
    if (surface_pt.y == Approx(min_.y))
    {
        return glm::vec3{ 0.0,-1.0,0.0 };
    }
    if (surface_pt.z == Approx(min_.z))
    {
        return glm::vec3{ 0.0,0.0,-1.0 };
    }
    if (surface_pt.x == Approx(max_.x))
    {
        return glm::vec3{ 1.0,0.0,0.0 };
    }
    if (surface_pt.y == Approx(max_.y))
    {
        return glm::vec3{ 0.0,1.0,0.0 };
    }
    if (surface_pt.z == Approx(max_.z))
    {
        return glm::vec3{ 0.0,0.0,1.0 };
    }
}


std::ostream& operator<<(std::ostream& os, Box const& b) {
    return b.print(os);
}