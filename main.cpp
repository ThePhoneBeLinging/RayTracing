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
  std::unique_ptr<EAL::Image> image = std::make_unique<EAL::Image>(screenWidth,screenHeight);
  while (not WindowShouldClose())
  {
    apple.computeWithShader(rays,{},image.get());
    BeginDrawing();
    image->updateTexture();
    image->draw();

    DrawFPS(0,0);
    EndDrawing();
  }
  return 0;
}
