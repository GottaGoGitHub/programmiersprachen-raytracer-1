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
#include <glm/glm.hpp>

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

void Renderer::render(Scene &scene, int fps) {
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

  ppm_.save("raytracer_" + filename_ + "_" + std::to_string(fps));
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
    return Color{1.0f, 1.0f, 1.0f};
  }

  std::sort(hitPoints.begin(), hitPoints.end());
  return shade(scene, *hitPoints.begin());
}

Color Renderer::shade(Scene &scene, HitPoint &hit) {

    Color res{ 0.1f, 0.1f, 0.1f };

    std::vector < std::shared_ptr<Light>> lights_from_hitpoint{  };

    for (auto const& light : scene.lights) {

        glm::vec3 dir_to_light{ glm::normalize(scene.lights[0]->position - hit.hitpoint) };
        glm::vec3 origin = hit.hitpoint + 0.1f * hit.normale;
        Ray ray_hp_light{ origin, dir_to_light };
        bool is_visible = true;

        for (auto const& shape : scene.objects) {

            HitPoint hits_other_shape = shape->intersect(ray_hp_light);

            if (hits_other_shape.gotHit == true) {
                is_visible = false;
                break;

            }

        }

        if (is_visible == true) {

            lights_from_hitpoint.push_back(light);

        }

    }

    for (auto const& light : lights_from_hitpoint) {

        glm::vec3 dir_to_light{ glm::normalize(scene.lights[0]->position - hit.hitpoint) };
        glm::vec3 dir_reflaction{ glm::normalize(glm::reflect(dir_to_light, glm::normalize(hit.normale))) };
        Color ambient_light = scene.ambient * hit.material.kd_;
        Color difuse_light = light->intensity * (std::max(0.0f, glm::dot(dir_to_light, glm::normalize(hit.normale))) * hit.material.ka_);
        Color specular_light = light->intensity * (std::pow(std::max(0.0f, glm::dot(dir_reflaction, hit.direction)), hit.material.m_) * hit.material.ks_);
        Color reflected_color = reflection(scene, hit);

        res = (ambient_light + difuse_light + specular_light) + hit.material.ks_ * reflected_color;

    }

    return res;
}

Color Renderer::reflection(Scene& scene, HitPoint const& hit) {
    glm::vec3 direction = glm::reflect(glm::normalize(hit.direction), glm::normalize(hit.normale));
    Ray ray{ hit.hitpoint + 0.1f * hit.normale, glm::normalize(direction) };
    return trace(scene, ray);
}

//Ray transformRay(Ray const& ray, glm::mat4 const& matrix)
//{
//    glm::vec4 origin{ ray.origin, 1.0f };
//    glm::vec4 direction{ ray.direction, 0.0f };
//
//    origin = matrix * origin;
//    direction = matrix * direction;
//    return Ray{ {origin.x, origin.y, origin.z}, glm::normalize(glm::vec3(direction.x, direction.y, direction.z)) };
//}