cmake_minimum_required(VERSION 3.24.0)

set(CMAKE_CXX_COMPILER "g++")

project(Kaine3DRenderer)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib/cmake/glfw3")

find_package(glfw3 3.3 REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_DLL ON)

add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)

add_executable(
    ${PROJECT_NAME} 
    src/main.cpp 
    src/util.cpp
    src/shader.cpp
    src/vertexbuffer.cpp
    src/VertexArray.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src/include)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/glm)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)




