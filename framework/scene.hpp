#ifndef SCENE_HPP
#define SCENE_HPP

#include<vector>
#include<string>

#include "shape.hpp"
#include "color.hpp"

struct Scene {
	std::string cam_name = "";
	std::string file_name = "";
	unsigned int xres = 0;
	unsigned int yres = 0;
	Color ambient = Color{ 0.0,0.0,0.0 };
};

#endif // SCENE_HPP