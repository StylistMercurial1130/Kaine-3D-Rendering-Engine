#ifndef __PRIMITIVES_H__
#define __PRIMITIVES_H__

#include <memory>
#include <vector>

#include "GLFW/glfw3.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Textures.h"
#include "Uniform.h"
#include "VertexArray.h"
#include "glad/glad.h"
#include "vertex.h"
#include "vertexbuffer.h"

class Primitive {
protected:
    VertexBuffer mVertexbuffer;
    VertexArray mVertexarray;
    IndexBuffer mIndexbuffer;
    std::vector<Vertex> mVertexdata;
    std::vector<unsigned int> mIndexBufferLayout;
    std::vector<Textures> mTextures;
    int mTextureindex;

private:
    void SetupPrimitive(std::vector<Vertex>&, std::vector<unsigned int>&);

public:
    Shader mShader;
    UniformHandler mUniformhandler;
    Primitive(std::vector<Vertex>&, std::vector<unsigned int>&);
    Primitive(const std::string&, const std::string&, std::vector<Vertex>&, std::vector<unsigned int>&);
    void BindRenderData();
    void AddTextures(const std::string&);
    void UseTexture(int, const std::string&);
};

class Triangle : public Primitive {
public:
    Triangle();
    Triangle(std::vector<Vertex>&, std::vector<unsigned int>&);
    Triangle(const std::string&, const std::string&, std::vector<Vertex>&, std::vector<unsigned int>&);
};

class Square : public Primitive {
public:
    Square();
    Square(std::vector<Vertex>&, std::vector<unsigned int>&);
    Square(const std::string&, const std::string&, std::vector<Vertex>&, std::vector<unsigned int>&);
};

class Pyramid : public Primitive {
public:
    Pyramid();
    Pyramid(std::vector<Vertex>&, std::vector<unsigned int>&);
    Pyramid(const std::string&, const std::string&, std::vector<Vertex>&, std::vector<unsigned int>&);
};

#endif
