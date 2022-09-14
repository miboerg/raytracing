cmake_minimum_required(VERSION 3.21)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp Vec3.hpp Sphere.hpp ray.hpp render.cpp renderer.hpp)
