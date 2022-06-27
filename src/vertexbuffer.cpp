#include "include/vertexbuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices){

    glGenBuffers(1,&vertexBufferObjectID);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObjectID);
    bufferData = vertices;
    PopulateBuffer(vertices);

}

void VertexBuffer::PopulateBuffer(std::vector<Vertex>& vertices){

    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * bufferData.size(),&bufferData[0],GL_STATIC_DRAW);

}
    

void VertexBuffer::BindBuffer(){

    glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObjectID);
    
}

void VertexBuffer::UnBindBuffer(){

    glBindBuffer(GL_ARRAY_BUFFER,0);

}

VertexBuffer::~VertexBuffer(){

    glDeleteBuffers(1,&vertexBufferObjectID);

}
