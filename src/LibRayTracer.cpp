//
// Created by Elias Aggergaard Larsen on 27/07-2025.
//

#include "LibRayTracer/LibRayTracer.hpp"
#include "raylib.h"
#include "LibRayTracer/Environenment.h"

LibRayTracer::LibRayTracer()
{
  InitWindow(Environenment::screenWidth, Environenment::screenHeight,"TITLE");
  initShader();
  image_ = std::make_unique<EAL::Image>(Environenment::screenWidth, Environenment::screenHeight);
}

#ifdef __APPLE__
#include "AppleMetal/AppleMetal.hpp"
void LibRayTracer::initShader()
{
  shader_ = std::make_unique<AppleMetal>();
}
#else
{
  void LibRayTracer::initShader()
  {

  }
}
#endif
void LibRayTracer::launch()
{
  std::vector<EAL::Ray> rays;
  rays.resize(Environenment::screenWidth * Environenment::screenHeight);

  std::vector<EAL::Sphere> spheres(0);

  while (not WindowShouldClose())
  {

    shader_->computeWithShader(rays, spheres, image_.get());
    BeginDrawing();
    image_->updateTexture();
    image_->draw();
    DrawFPS(0,0);
    EndDrawing();
  }
}
