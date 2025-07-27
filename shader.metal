#include <metal_stdlib>
using namespace metal;

kernel void vectorKernel(device const float3* inVectors  [[ buffer(0) ]],
                         device float3* outVectors       [[ buffer(1) ]],
                         uint id                         [[ thread_position_in_grid ]]) {
    float3 input = inVectors[id];
    float3 output = float3(input.x,input.y,input.z);
    outVectors[id] = output;
}