    cmake_minimum_required(VERSION 3.0)

project(kaa)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(kaactl)
add_subdirectory(kaasvc)
add_subdirectory(kaafs)
