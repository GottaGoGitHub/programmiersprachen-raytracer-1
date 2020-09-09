#include <renderer.hpp>
#include <window.hpp>
#include "sdfloader.hpp"
#include "scene.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "camera.hpp"
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

  // if(argc < 2) {
  //   std::cout << "Usage: " << argv[0] << " No File Path given" << std::endl;
    
  //   return -1; 
  // }

        Scene scene{};

        Color red{ 255, 0, 0 };

        Material blue{ "blue", {0.0f, 0.0f, 0.7f}, {0.0f, 0.0f, 0.1f}, {0.0f, 0.0f, 0.1f}, 10.0f };

        Light light{};
        auto l1 = std::make_shared<Light>(light);
        scene.lights.push_back(l1);

        Sphere kreis_eins{ "kreis_eins", blue, {0.0f, 0.0f, -20.0f}, 2.0f };
        auto s1 = std::make_shared<Sphere>(kreis_eins);
        scene.objects.push_back(s1);

        unsigned const image_width = 600;
        unsigned const image_height = 600;

        scene.xres = image_width;
        scene.yres = image_height;
        //std::string const filename = "./checkerboard.ppm";

        Renderer renderer{ scene.yres, scene.xres, scene.file_name };

        renderer.render(scene);
    //}

 Window window{{image_width, image_height}};

  while (!window.should_close()) {
    if (window.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      window.close();
    }
    window.show(renderer.color_buffer());
  }

  std::cout << scene.lights[0]->name << std::endl;

  return 0;
}
