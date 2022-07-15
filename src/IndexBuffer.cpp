#include "include/IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
    glGenBuffers(1, &indexBufferObjectId);
}

void IndexBuffer::BindIndexBuffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObjectId);
}

void IndexBuffer::PopulateIndexBuffer(std::vector<unsigned int>& indexElements)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexElements.size() * sizeof(unsigned int), &indexElements[0], GL_STATIC_DRAW);
}

void IndexBuffer::UnBindIndexBuffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &indexBufferObjectId);
}