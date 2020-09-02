#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP

#include <iostream> // debug prints
#include <fstream>  // open / read / write /close files
#include <sstream>  //stringstream -> easy parsing mechanics
#include <string>   // buffer lines read from file
#include "scene.hpp"
#include "material.hpp"
#include "light.hpp"
#include "color.hpp"
#include "shape.hpp"

class SdfLoader {

	public:
		void load(char* argv[], Scene &scene) const;
};

#endif //SDFLOADER_HPP
