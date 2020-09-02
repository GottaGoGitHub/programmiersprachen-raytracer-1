#include <renderer.hpp>
#include <window.hpp>
#include "sdfloader.hpp"
#include "scene.hpp"
#include "shape.hpp"
#include "ppmwriter.hpp"
#include "light.hpp"

#include <GLFW/glfw3.h>
#include <thread>
#include <utility>
#include <cmath>
#include <string>
#include <map>
#include <iostream>


//now single threaded again
int main(int argc, char* argv[])
{

  if(argc < 2) {
    std::cout << "Usage: " << argv[0] << " No File Path given" << std::endl;
    
    return -1; 
  }

  SdfLoader sdf{};
  Scene scene{};

  sdf.load(argv, scene);


  std::cout << scene.file_name << std::endl;
  std::cout << "yewew" << std::endl;

  for(auto elem : scene.material_map) {
    std::cout << elem.first << ", " << elem.second->name_ << ", " << elem.second->ka_ << ", " << elem.second->kd_ << ", " << elem.second->ks_ << ", " << elem.second->m_ << std::endl;
  }


  unsigned const image_width = 800;
  unsigned const image_height = 600;
  //std::string const filename = "./checkerboard.ppm";

  // Renderer renderer{scene.xres, scene.yres, scene.file_name};

  // renderer.render();

  // Window window{{image_width, image_height}};

  // while (!window.should_close()) {
  //   if (window.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
  //     window.close();
  //   }
  //   window.show(renderer.color_buffer());
  // }

  // return 0;
}
