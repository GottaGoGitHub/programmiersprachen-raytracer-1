#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <glm/vec3.hpp>

#include "color.hpp"
#include "scene.hpp"
#include "shape.hpp"

Scene sdfloader(std::string const& file) {
	Scene scene;
	std::string line;
	std::ifstream input_file;
	input_file.open(file);

	if (input_file.is_open()) {
		std::cout << "File opened\n";
		while (getline(input_file, line) {
			std::stringstream ss;
			ss << line;
			std::string keyword;
			ss >> keyword;

			if (keyword == "define") {
				ss >> keyword;

				if (keyword == "sphere") {
					std::string name, mat;
					float x, y, z, rad;

					ss >> name;
					ss >> mat;

					ss >> x;
					ss >> y;
					ss >> z;
					glm::vec3 pos = glm::vec3(x, y, z);

					ss >> rad;

					std::shared_ptr<Shape> sphere(new Sphere(pos, rad, name, scene.find_material(mat)));
					scene.shape_map[name] = sphere;
					//std::cout<<"Loaded sphere: "<<name<<".\n";
				}

				if (keyword == "box") {
					std::string name, mat;
					float x, y, z;

					ss >> name;
					ss >> mat;

					ss >> x;
					ss >> y;
					ss >> z;
					glm::vec3 min = glm::vec3(x, y, z);

					ss >> x;
					ss >> y;
					ss >> z;
					glm::vec3 max = glm::vec3(x, y, z);

					std::shared_ptr<Shape> box(new Box(min, max, name, scene.find_material(mat)));
					scene.shape_map[name] = box;
					//std::cout<<"Loaded box: "<<name<<".\n";
				}
			}

			if (keyword == "ambient") {
				float x, y, z;
				ss >> x;
				ss >> y;
				ss >> z;
				Color color(x, y, z);
				scene.ambient = color;
				//std::cout<<"Loaded ambient light.\n";
			}
		}
		input_file.close();
	}
	else {
		std::cout << "Datei konnte nicht geöffnet werden!";
	}
	
	return scene;
}
#endif // SDLOADER_HPP