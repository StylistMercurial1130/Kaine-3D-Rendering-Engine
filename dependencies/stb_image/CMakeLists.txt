cmake_minimum_required(VERSION 3.0)

project(stb_image)

add_library(stb_image ${CMAKE_CURRENT_SOURCE_DIR}/include/stb_image.h ${CMAKE_CURRENT_SOURCE_DIR}/src/stb_image.cpp)
target_include_directories(stb_image PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)