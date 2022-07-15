#include "include/Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertexData, std::vector<unsigned int>& indexBufferData)
{
    mVertexdata = vertexData;
    mIndexbufferdata = indexBufferData;
    mVertexbufferobject = std::make_shared<VertexBuffer>(vertexData);
    mIndexbufferobject = std::make_shared<IndexBuffer>();
    mVertexarrayobject = std::make_shared<VertexArray>();
    mVertexarrayobject->BindVertexArray();
    mIndexbufferobject->BindIndexBuffer();
    mIndexbufferobject->PopulateIndexBuffer(indexBufferData);
    mVertexarrayobject->BindVertexArray();
    mVertexarrayobject->CreateLayout(3, GL_FLOAT, true, 0, sizeof(Vertex), mVertexbufferobject.get());
    mVertexarrayobject->CreateLayout(3, GL_FLOAT, true, 12, sizeof(Vertex), mVertexbufferobject.get());
    mVertexarrayobject->CreateLayout(3, GL_FLOAT, true, 24, sizeof(Vertex), mVertexbufferobject.get());
}

void Mesh::Draw()
{
    glDrawElements(GL_TRIANGLES, mIndexbufferdata.size(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::AddTextures(const std::string& textureLocation, int unit)
{
    if (mTextures.find(unit) == mTextures.end())
        mTextures.insert({ unit, std::make_shared<Textures>(textureLocation) });
}

void Mesh::BindMeshTextures(UniformHandler& uniformHandler, Shader& shader)
{
    for (auto mapData : mTextures) {
        mTextures[mapData.first]->BindTextures(mapData.first);
        uniformHandler.ModifyUniform1i("textureSample2D", shader.GetShaderId(), mapData.first);
    }
}

void Mesh::BindMeshTextures(int unit, UniformHandler& uniformHandler, Shader& shader)
{
    if (mTextures.find(unit) != mTextures.end()) {
        mTextures[unit]->BindTextures(unit);
        uniformHandler.ModifyUniform1i("textureSample2D", shader.GetShaderId(), unit);
    }
}