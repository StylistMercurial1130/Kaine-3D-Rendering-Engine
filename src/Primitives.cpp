#include "include/Primitives.h"

static std::vector<Vertex> TriangleDefaultVertexData = {
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) },
    Vertex { glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }
};

static std::vector<Vertex> SquareDefaultVertexData = {
    Vertex { glm::vec3(-0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(-0.5f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) },
    Vertex { glm::vec3(+0.5f, -0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }
};

static std::vector<Vertex> PyramidDefaultVertexData = {
    //TRIANGLE_1
    Vertex { glm::vec3(+0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V0
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V1
    Vertex { glm::vec3(-0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V2
    //TRIANGLE_2
    Vertex { glm::vec3(-0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V3
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V4
    Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V5
    //TRIANGLE_3
    Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V6
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V7
    Vertex { glm::vec3(+0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V8
    //TRIANGLE_4
    Vertex { glm::vec3(+0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V9
    Vertex { glm::vec3(+0.0f, +0.5f, +0.0f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V10
    Vertex { glm::vec3(+0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V11
    //TRIANGLE_5
    Vertex { glm::vec3(-0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V12
    Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V13
    Vertex { glm::vec3(+0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V14
    //TRINALGE_6
    Vertex { glm::vec3(+0.5f, -0.5f, -0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.0f, +0.0f) }, //V15
    Vertex { glm::vec3(+0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+0.5f, +1.0f) }, //V16
    Vertex { glm::vec3(-0.5f, -0.5f, +0.5f), glm::vec3(+0.0f, +0.0f, +0.0f), glm::vec2(+1.0f, +0.0f) }, //V17
};

static std::vector<unsigned int> TriangleDefaultIndexBufferData = { 0, 1, 2 };
static std::vector<unsigned int> SquareDefaultIndexBufferData = { 0, 1, 2,
    0, 3, 2 };

static std::vector<unsigned int> pyramidDefaultIndexBuffer = {
    0, 1, 2,
    3, 4, 5,
    6, 7, 8,
    9, 10, 11,
    12, 13, 14,
    15, 16, 17
};

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

Triangle::Triangle(std::vector<Vertex>& vertexBufferData, std::vector<unsigned int>& indexBufferData)
    : Primitive(vertexBufferData, indexBufferData)
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

Square::Square(std::vector<Vertex>& vertexBufferData, std::vector<unsigned int>& indexBufferData)
    : Primitive(vertexBufferData, indexBufferData)
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

Pyramid::Pyramid()
    : Primitive(PyramidDefaultVertexData, pyramidDefaultIndexBuffer)
{
}

Pyramid::Pyramid(std::vector<Vertex>& vertexBufferData, std::vector<unsigned int>& indexBufferdata)
    : Primitive(vertexBufferData, indexBufferdata)
{
}

Pyramid::Pyramid(const std::string& fragmentShaderLocation, const std::string& vertexShaderLocation,
    std::vector<Vertex>& vertexBufferData, std::vector<unsigned int>& indexBufferData)
    : Primitive(fragmentShaderLocation, vertexShaderLocation, vertexBufferData, indexBufferData)
{
}