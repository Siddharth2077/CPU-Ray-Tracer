# CPU Ray-Tracer

This project is a C++ implementation of Peter Shirley's _Ray Tracing in One Weekend_ series. It builds a simple CPU-based ray tracer from scratch, showcasing fundamental rendering techniques including ray-sphere intersections, diffuse materials, shadows, reflections, and antialiasing.

## Preview

![final_render](https://github.com/user-attachments/assets/dece8e91-70e3-43fa-801e-7e0e518351c6)
> Final render with 100 samples/pixel

## Book Reference

This implementation follows the structure and concepts introduced in:

- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)  by Peter Shirley

## Features

- Basic vector and ray math
- Recursive ray tracing
- Diffuse, metal, and dielectric materials
- Antialiasing

## Dependencies

- C++17 or later
- Standard C++ libraries only (no external dependencies)

## Building

### Using CMake (Recommended)

```bash
git clone https://github.com/Siddharth2077/CPU-Ray-Tracer.git
cd raytracing-in-one-weekend
mkdir build && cd build
cmake ..
make
```
