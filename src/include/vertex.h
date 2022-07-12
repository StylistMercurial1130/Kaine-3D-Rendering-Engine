#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"


struct Vertex {

    glm::vec3 postion;
    glm::vec3 colour;
    glm::vec2 textureCordinates;
};

#endif
