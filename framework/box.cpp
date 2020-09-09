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

    std::vector<HitPoint> hitpoints{};
    
    //intersect with left-hand side
    if (ray.direction.x != Approx(0.0f)) {

        float t = (-ray.origin.x + min_.x) / ray.direction.x;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (y >= min_.y && y <= max_.y && z <= min_.z && z >= max_.z && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ -1.0f, 0.0f, 0.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    //intersect with right-hand side
    if (ray.direction.x != Approx(0.0f)) {

        float t = (-ray.origin.x + min_.x) / ray.direction.x;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (y >= min_.y && y <= max_.y && z <= min_.z && z >= max_.z && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ 1.0f, 0.0f, 0.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    //intersect with upper side
    if (ray.direction.y != Approx(0.0f)) {

        float t = (-ray.origin.y + min_.y) / ray.direction.y;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (x >= min_.x && x <= max_.x && z <= min_.z && z >= max_.z && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ 0.0f, 1.0f, 0.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    //intersect with lower side
    if (ray.direction.y != Approx(0.0f)) {

        float t = (-ray.origin.y + min_.y) / ray.direction.y;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (x >= min_.x && x <= max_.x && z <= min_.z && z >= max_.z && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ 0.0f, -1.0f, 0.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    //intersect with front side
    if (ray.direction.z != Approx(0.0f)) {

        float t = (-ray.origin.z + min_.z) / ray.direction.z;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (x >= min_.x && x <= max_.x && y >= min_.y && y <= max_.y && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ 0.0f, 0.0f, 1.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    //intersect with back side
    if (ray.direction.z != Approx(0.0f)) {

        float t = (-ray.origin.z + min_.z) / ray.direction.z;
        float x = ray.origin.x + t * ray.direction.x;
        float y = ray.origin.y + t * ray.direction.y;
        float z = ray.origin.z + t * ray.direction.z;

        if (x >= min_.x && x <= max_.x && y >= min_.y && y <= max_.y && t > 0) {
            float distance = sqrt(pow(ray.origin.x - x, 2) + pow(ray.origin.y - y, 2) + pow(ray.origin.z - z, 2));
            HitPoint hit{ true, distance, name_, glm::vec3{x, y, z}, ray.direction, glm::vec3{ 0.0f, 0.0f, -1.0f }, material_ };
            hitpoints.push_back(hit);
        }

    }

    if (hitpoints.empty()) {
        return HitPoint{};
    }

    else {
        std::sort(hitpoints.begin(), hitpoints.end());

        return *hitpoints.begin();
    }

    //return hit;

}


glm::vec3 Box::calc_normal(HitPoint const& hit) {
    auto surface_pt = hit.hitpoint;
    glm::vec3 res;
    if (surface_pt.x == Approx(min_.x))
    {
        res = { -1.0f,0.0f,0.0f };
    }
    if (surface_pt.y == Approx(min_.y))
    {
        res = { 0.0f,-1.0f,0.0f };
    }
    if (surface_pt.z == Approx(min_.z))
    {
        res = { 0.0f,0.0f,-1.0f };
    }
    if (surface_pt.x == Approx(max_.x))
    {
        res = { 1.0f,0.0f,0.0f };
    }
    if (surface_pt.y == Approx(max_.y))
    {
        res = { 0.0f,1.0f,0.0f };
    }
    if (surface_pt.z == Approx(max_.z))
    {
        res = { 0.0f,0.0f,1.0f };
    }

    return res;

}


std::ostream& operator<<(std::ostream& os, Box const& b) {
    return b.print(os);
}