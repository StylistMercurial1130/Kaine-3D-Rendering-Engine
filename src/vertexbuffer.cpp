#include "include/vertexbuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices){

    glGenBuffers(1,&vertexBufferObjectID);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObjectID);
    bufferData = vertices;
    PopulateBuffer(vertices);

    for(int i = 0;i < bufferData.size();i++){

        auto postion = bufferData[i].postion;
        auto colour = bufferData[i].colour;

        std :: cout << postion.x << " " << postion.y << " " << postion.z << " " << '\n';
        std :: cout << colour.x << " " << colour.y << " " << colour.z << " " << '\n';
    }

}

void VertexBuffer::PopulateBuffer(std::vector<Vertex> vertices){

    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex) * bufferData.size(),&bufferData[0],GL_STATIC_DRAW);

}


void VertexBuffer::BindBuffer(){

    glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObjectID);
    
}

void VertexBuffer::UnBindBuffer(){

    glBindBuffer(GL_ARRAY_BUFFER,0);

}
