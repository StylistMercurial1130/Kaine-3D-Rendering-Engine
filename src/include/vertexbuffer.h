#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__
#include <vector>
#include "glad/glad.h"
#include "vertex.h"

class VertexBuffer{

private:
    
    unsigned int vertexBufferObjectID;
    std::vector<Vertex> bufferData;

public:

    VertexBuffer(std::vector<Vertex> vertices);
    void BindBuffer();
    void PopulateBuffer(std::vector<Vertex> vertices);
    static void UnBindBuffer();

};


#endif