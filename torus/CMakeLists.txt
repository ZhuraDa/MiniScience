cmake_minimum_required(VERSION 3.14)
project(torus)

set(CMAKE_CXX_STANDARD 20)

add_executable(torus main.cpp)

target_link_libraries(torus gmsh)