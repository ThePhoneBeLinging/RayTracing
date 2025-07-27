//
// Created by Elias Aggergaard Larsen on 27/07-2025.
//

#ifndef LIBRAYTRACER_H
#define LIBRAYTRACER_H
#include "LibDataTypes/IComputeShader.h"
#include "LibDataTypes/Image.h"


class LibRayTracer
{
public:
  LibRayTracer();
  void initShader();
  void launch();
private:
  std::unique_ptr<EAL::Image> image_;
  std::unique_ptr<EAL::IComputeShader> shader_;
};



#endif //LIBRAYTRACER_H
