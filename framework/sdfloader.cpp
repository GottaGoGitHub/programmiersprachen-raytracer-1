#include "sdfloader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

void SdfLoader::load(char* argv[], Scene &scene) const {

  std::string const in_file_path = argv[1];

  // open file in read-only && ASCII mode 
  std::ifstream in_file(in_file_path, std::ios::in);
  
  std::string line_buffer;

  int32_t line_count = 0;

  std::string identifier;    
  std::string class_name;

  while( std::getline(in_file, line_buffer)  ) {
    //std::cout << ++line_count << ": " << line_buffer << std::endl;
    ++line_count;
    
    //construct stringstream using line_buffer string
    std::istringstream in_sstream(line_buffer);
    
    in_sstream >> identifier;

    std::cout << "Identifier content: " << identifier << std::endl;
    
    // check for shapes / materials / lights
    if("define" == identifier) {
      in_sstream >> class_name; 
  
      // check for specific shape
      if("shape" == class_name) {
         //check for shape type, then: parse attributes (including material lookup)
      } else if ("material" == class_name) {
        //parse material attributes
        std::string material_name;
        float ka_red, ka_green, ka_blue;
        float kd_red, kd_green, kd_blue;
        float ks_red, ks_green, ks_blue;
        float m;
 
        in_sstream >> material_name;
        in_sstream >> ka_red >> ka_green >> ka_blue; 
        Color ka{ka_red, ka_green, ka_blue};
        in_sstream >> kd_red >> kd_green >> kd_blue;
        Color kd{kd_red, kd_green, kd_blue};
        in_sstream >> ks_red >> ks_green >> ks_blue;
        Color ks{ks_red, ks_green, ks_blue};
        in_sstream >> m;
 
        std::cout << material_name << std::endl;
        std::cout << ka_red  << " " << ka_green << " " << ka_blue << std::endl;
        std::cout << kd_red  << " " << kd_green << " " << kd_blue << std::endl;
        std::cout << ks_red  << " " << ks_green << " " << ks_blue << std::endl;
        std::cout << m << std::endl;

        // Material new_material{material_name, ka, kd, ks, m};
        // auto mat = std::make_shared<Material>(new_material);
        // scene.material_map.insert(std::pair<std::string, std::shared_ptr<Material>>(material_name, mat));

      } else if ("light" == class_name) {

      } else {
        std::cout << "Line was not valid!" << std::endl;
      }
    }  

  }
  
  // close file
  in_file.close();
}