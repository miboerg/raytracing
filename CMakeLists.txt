cmake_minimum_required(VERSION 3.21)
project(raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp objects/Sphere.h utils/ray.h objects/World.cpp utils/Color.h utils/src/Vec3.cpp utils/include/Vec3.h objects/LightSource.h lib/json.hpp settings.json)
