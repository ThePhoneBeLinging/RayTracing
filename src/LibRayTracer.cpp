//
// Created by Elias Aggergaard Larsen on 27/07-2025.
//

#include "LibRayTracer/LibRayTracer.hpp"

#include "LibRayTracer/Environenment.h"

LibRayTracer::LibRayTracer() : texture_(LoadTextureFromImage(GenImageColor(Environenment::screenWidth, Environenment::screenHeight,WHITE)))
{

}

void LibRayTracer::launch()
{
  while (not WindowShouldClose())
  {
    BeginDrawing();
    UpdateTexture(texture_,colors.data());
    DrawTexture(texture_,0,0,WHITE);
    DrawFPS(0,0);
    EndDrawing();
  }
}
