#ifndef __MESH_H__
#define __MESH_H__

#include "IndexBuffer.h"
#include "Shader.h"
#include "Textures.h"
#include "Uniform.h"
#include "VertexArray.h"
#include "vertex.h"
#include "vertexbuffer.h"
#include <map>
#include <memory>

class Mesh {
private:
    std::shared_ptr<VertexBuffer> mVertexbufferobject;
    std::shared_ptr<VertexArray> mVertexarrayobject;
    std::shared_ptr<IndexBuffer> mIndexbufferobject;
    std::map<int, std::shared_ptr<Textures>> mTextures;
    std::vector<Vertex> mVertexdata;
    std::vector<unsigned int> mIndexbufferdata;

public:
    Mesh(std::vector<Vertex>&, std::vector<unsigned int>&);
    void Draw();
    void AddTextures(const std::string&, int);
    void BindMeshTextures(UniformHandler& uniformHandler, Shader& shader);
    void BindMeshTextures(int, UniformHandler& uniformHandler, Shader& shader);
};

#endif