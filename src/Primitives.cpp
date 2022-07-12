#include "include/Primitives.h"

static std::vector<Vertex> TriangleDefaultVertexData = {
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.5f, +1.0f) },
    Vertex { glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+1.0f, +0.0f) }
};

static std::vector<Vertex> SquareDefaultVertexData = {
    Vertex { glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(-0.5f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f),
        glm::vec2(+0.0f, +0.0f) }
};

static std::vector<unsigned int> TriangleDefaultIndexBufferData = { 0, 1, 2 };
static std::vector<unsigned int> SquareDefaultIndexBufferData = { 0, 1, 2,
    0, 3, 2 };

void Primitive::SetupPrimitive(std::vector<Vertex>& vertexData,
    std::vector<unsigned int>& indexBufferData)
{
    mVertexdata = vertexData;
    mIndexBufferLayout = indexBufferData;
    mIndexbuffer.BindIndexBuffer();
    mIndexbuffer.PopulateIndexBuffer(mIndexBufferLayout);
    mVertexarray.BindVertexArray();
    mVertexarray.CreateLayout(3, GL_FLOAT, true, 0, sizeof(Vertex), &mVertexbuffer);
    mVertexarray.CreateLayout(3, GL_FLOAT, true, 12, sizeof(Vertex), &mVertexbuffer);
    mVertexarray.CreateLayout(2, GL_FLOAT, true, 24, sizeof(Vertex), &mVertexbuffer);
    mShader.CompileShaders();
}

Primitive::Primitive(std::vector<Vertex>& vertexData,
    std::vector<unsigned int>& indexBufferData)
    : mShader("./shaders/shader.vert", "./shaders/shader.frag")
    , mVertexbuffer(vertexData)
    , mTextureindex(-1)
{
    SetupPrimitive(vertexData, indexBufferData);
}

Primitive::Primitive(const std::string& vertexShaderLocation,
    const std::string& fragmentShaderLocation,
    std::vector<Vertex>& vertexData,
    std::vector<unsigned int>& indexBufferData)
    : mVertexbuffer(vertexData)
    , mShader(vertexShaderLocation, fragmentShaderLocation)
    , mTextureindex(-1)
{
    SetupPrimitive(vertexData, indexBufferData);
}

void Primitive::BindRenderData()
{
    if (mTextureindex != -1)
        mTextures[mTextureindex].BindTextures(mTextureindex);
    mShader.UseShaderProgram();
    mIndexbuffer.BindIndexBuffer();
    mVertexarray.BindVertexArray();
}

void Primitive::AddTextures(const std::string& textureFile)
{
    if (fopen(textureFile.c_str(), "r")) {
        mTextures.push_back(Textures(textureFile));
        mTextureindex++;
    }
}

void Primitive::UseTexture(int index, const std::string& uniformHandleName)
{
    if (index <= mTextureindex) {
        mTextures[index].BindTextures(index);
        mUniformhandler.ModifyUniform1i(uniformHandleName, mShader.GetShaderId(), index);
    }
}

Triangle::Triangle()
    : Primitive(TriangleDefaultVertexData, TriangleDefaultIndexBufferData)
{
}

Triangle::Triangle(const std::string& vertexShaderLocation,
    const std::string& fragmentShaderLocation,
    std::vector<Vertex>& vertexData,
    std::vector<unsigned int>& indexBufferData)
    : Primitive(vertexShaderLocation, fragmentShaderLocation, vertexData,
        indexBufferData)
{
}

Square::Square()
    : Primitive(SquareDefaultVertexData, SquareDefaultIndexBufferData)
{
}

Square::Square(const std::string& vertexShaderLocation,
    const std::string& fragmentShaderLocation,
    std::vector<Vertex>& vertexData,
    std::vector<unsigned int>& indexBufferData)
    : Primitive(vertexShaderLocation, fragmentShaderLocation, vertexData,
        indexBufferData)
{
}
