#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>
#include <string>
#include <map>

#include "shape.hpp"
#include "color.hpp"
#include "material.hpp"
#include "light.hpp"
#include "camera.hpp"

struct Scene {

	//std::shared_ptr<Material> find_material(std::string const& mat_name) const;

	std::map<std::string, std::shared_ptr<Material>> material_map{};
	std::vector<std::shared_ptr<Shape>> objects{};
	std::vector<std::shared_ptr<Light>> lights{};
	Camera cam{};
	std::string cam_name = "";
	std::string file_name = "Szene";
	unsigned int xres = 800;
	unsigned int yres = 600;
	Color ambient = Color{0.0,0.0,0.0};
};

#endif // SCENE_HPP