#include <iostream>

#include "raylib.h"
#include "AppleMetal/AppleMetal.hpp"

int main()
{
  int screenWidth = 1280, screenHeight = 720;
  InitWindow(screenWidth,screenHeight,"TITLE");
  auto texture = LoadTextureFromImage(GenImageColor(screenWidth,screenHeight,WHITE));
  auto apple = AppleMetal();
  std::vector<EAL::Ray> rays;
  rays.resize(screenWidth*screenHeight);

  while (not WindowShouldClose())
  {
    for (int i = 0; i < screenWidth*screenHeight; i++)
    {
      rays[i].vector = {255,255,255};
    }
    auto result = apple.computeWithShader(rays,{});
    std::vector<Color> colors;
    colors.resize(screenWidth*screenHeight);
    for (int i = 0; i < result.size(); i++)
    {
      auto localResult = result[i];
      colors[i].r = localResult.x;
      colors[i].g = localResult.y;
      colors[i].b = localResult.z;
      colors[i].a = 255;
    }
    BeginDrawing();
    UpdateTexture(texture,colors.data());
    DrawTexture(texture,0,0,WHITE);
    DrawFPS(0,0);
    EndDrawing();
  }
  return 0;
}
