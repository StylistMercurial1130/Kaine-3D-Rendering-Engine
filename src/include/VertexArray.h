#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

#include "glad/glad.h"
#include "vertexbuffer.h"
#include <map>
#include <memory>

class VertexArrayLayout {

public:
    unsigned int Size;
    GLenum Type;
    bool Normalized;
    int Offset;

    VertexArrayLayout(unsigned int size, GLenum type, bool normalized, int offset);
};

class VertexArray {

private:
    unsigned int vertexArrayObjectID;
    unsigned int index;

    std::map<int, std::unique_ptr<VertexArrayLayout>> IndexLayoutMap;

public:
    VertexArray();
    void CreateLayout(unsigned int size, GLenum type, bool normalized, int offset, unsigned int stride, VertexBuffer* vertexBuffer);
    void BindVertexArray();
    ~VertexArray();
};

#endif