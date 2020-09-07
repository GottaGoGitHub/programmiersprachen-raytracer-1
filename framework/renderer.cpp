// -----------------------------------------------------------------------------
// Copyright  : (C) 2014-2017 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------


#define _USE_MATH_DEFINES

#include "renderer.hpp"
#include <algorithm>
#include <cmath>

Renderer::Renderer(unsigned w, unsigned h, std::string const& file)
  : width_(w)
  , height_(h)
  , color_buffer_(w*h, Color{0.0, 0.0, 0.0})
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render()
{
  std::size_t const checker_pattern_size = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      if ( ((x/checker_pattern_size)%2) != ((y/checker_pattern_size)%2)) {
        p.color = Color{0.0f, 1.0f, float(x)/height_};
      } else {
        p.color = Color{1.0f, 0.0f, float(y)/width_};
      }

      write(p);
    }
  }
  ppm_.save(filename_);
}

void Renderer::render(Scene &scene) {
  for(int i = 0; i < (int)height_; ++i){
    for(int k = 0; k < (int)width_; ++k){
      
      float cam_angle = scene.cam.phi * M_PI / 180.0f;

      float distance_to_image = (width_ / 2) / std::tan(cam_angle / 2);

      float ray_x = (int)width_ / 2 - ((int)width_ - i);
      float ray_y = (int)height_ / 2 - ((int)height_ - k);

      Ray ray{glm::vec3(0.0f, 0.0f, 0.0f), glm::normalize(glm::vec3(ray_x, ray_y, -distance_to_image))};

      Color pixel_color = trace(scene, ray);

      Pixel pixel{(unsigned)i, (unsigned)k};

      pixel.color = pixel_color;

      write(pixel);
    }
  }

  ppm_.save("test" + filename_);
}

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= color_buffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    color_buffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}

Color Renderer::trace(Scene &scene, Ray &ray) {
  
  std::vector<HitPoint> hitPoints{};

  for(auto object : scene.objects) {
    HitPoint hit = object->intersect(ray);

    if(hit.gotHit == true) {
      hitPoints.push_back(hit);
    }
  }

  if(hitPoints.empty()) {
    return Color{0.0f, 0.0f, 0.0f};
  }

  std::sort(hitPoints.begin(), hitPoints.end());
  return shade(scene, *hitPoints.begin());
}

Color Renderer::shade(Scene &scene, HitPoint &hit) {

  Color ambient_color = scene.ambient * hit.material.ka_;

  Color tmp = scene.lights[0]->intensity * hit.material.kd_;

  glm::vec3 direction_to_light = glm::normalize(scene.lights[0]->position - hit.hitpoint);

  glm::vec3 norm = glm::normalize(hit.normale);

  glm::vec3 n = norm * direction_to_light;

  Color n_transformed{n.x, n.y, n.z};

  Color res = n_transformed * ambient_color * tmp;

  // for(auto lightsource : scene.lights) {

  //   glm::vec3 dir{0.0f, 0.0f, 0.0f};

  //   dir = lightsource->position - hit.hitpoint;

  //   Ray connection{lightsource->position, dir};

  //   for(auto object : scene.objects) {
  //     HitPoint hit = object->intersect(connection);

  //     float dist = hit.distance;
  //   }



  // }

  return res;
}

