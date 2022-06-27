#include "include/VertexArray.h"
#include <iostream>

VertexArray::VertexArray() : index(0){

    glGenVertexArrays(1,&vertexArrayObjectID);

}

VertexArrayLayout::VertexArrayLayout(unsigned int size,GLenum type,bool normalized,int offset)
:Size(size) , Type(type),Normalized(normalized),Offset(offset){



}

void VertexArray::BindVertexArray(){

    glBindVertexArray(vertexArrayObjectID);

}

void VertexArray::CreateLayout(unsigned int size,GLenum type,bool normalized,int offset,unsigned int stride,VertexBuffer* vertexBuffer){

    IndexLayoutMap.insert({
        index,
        std::make_unique<VertexArrayLayout>(size,type,normalized,offset)
    });

    vertexBuffer->BindBuffer();

    glEnableVertexAttribArray(index);

    std::cout   << "Index : " <<index << '\n'
                << "Size : " <<IndexLayoutMap[index]->Size <<  '\n'
                << "Type : " <<IndexLayoutMap[index]->Type << '\n'
                << "Normalized : "<<IndexLayoutMap[index]->Normalized << '\n'
                << "Stride : "<<stride << '\n'
                << "Offset : "<<IndexLayoutMap[index]->Offset << '\n';
                
    glVertexAttribPointer(
        index,
        IndexLayoutMap[index]->Size,
        IndexLayoutMap[index]->Type,
        IndexLayoutMap[index]->Normalized,
        stride,
        (void*)IndexLayoutMap[index]->Offset
    );

    index++;

}

