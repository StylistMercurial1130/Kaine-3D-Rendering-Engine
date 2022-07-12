#include "include/Primitives.h"

static std::vector<Vertex> TriangleDefaultVertexData = {
	Vertex{glm::vec3(+0.0f,+0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.5f,+1.0f)},
	Vertex{glm::vec3(-0.5f,-0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)},
	Vertex{glm::vec3(+0.5f,-0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+1.0f,+0.0f)}
};

static std::vector<Vertex> SquareDefaultVertexData = {
	Vertex{glm::vec3(-1.0f,-1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)},
	Vertex{glm::vec3(-1.0f,+1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)},
	Vertex{glm::vec3(+1.0f,+1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)},
	Vertex{glm::vec3(+1.0f,-1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)}
};

static std::vector<unsigned int> TriangleDefaultIndexBufferData = {0 , 1 , 2};
static std::vector<unsigned int> SquareDefaultIndexBufferData = {0 , 1 , 2 ,3};

void Primitive::SetupPrimitive(std::vector<Vertex>& vertexData,std::vector<unsigned int>& indexBufferData) {

	mVertexdata = vertexData;
	mIndexBufferLayout = indexBufferData;
	mIndexbuffer.BindIndexBuffer();
	mIndexbuffer.PopulateIndexBuffer(mIndexBufferLayout);
	mVertexarray.BindVertexArray();
	mVertexarray.CreateLayout(3,GL_FLOAT,true,0,sizeof(Vertex),&mVertexbuffer);
	mShader.CompileShaders();

}

Primitive::Primitive(std::vector<Vertex>& vertexData,std::vector<unsigned int>& indexBufferData) 
: mShader("./shaders/shader.vert","./shaders/shader.frag") , mVertexbuffer(vertexData){

	SetupPrimitive(vertexData,indexBufferData);

}

Primitive::Primitive(const std::string& vertexShaderLocation,const std::string& fragmentShaderLocation,
std::vector<Vertex>& vertexData,std::vector<unsigned int>& indexBufferData) 
: mVertexbuffer(vertexData) , mShader(vertexShaderLocation,fragmentShaderLocation) {
	
	SetupPrimitive(vertexData,indexBufferData);

}	

void Primitive::BindRenderData() {

	mVertexbuffer.BindBuffer();
	mShader.UseShaderProgram();
	mIndexbuffer.BindIndexBuffer();
	mVertexarray.BindVertexArray();
	
}

Triangle::Triangle() 
: Primitive(TriangleDefaultVertexData,TriangleDefaultIndexBufferData) {}

Triangle::Triangle(const std::string& vertexShaderLocation,const std::string& fragmentShaderLocation,
std::vector<Vertex>& vertexData,std::vector<unsigned int>& indexBufferData) 
: Primitive(vertexShaderLocation,fragmentShaderLocation,vertexData,indexBufferData) {}

Square::Square() 
: Primitive(SquareDefaultVertexData,SquareDefaultIndexBufferData) {}

Square::Square(const std::string& vertexShaderLocation,const std::string& fragmentShaderLocation,
std::vector<Vertex>& vertexData,std::vector<unsigned int>& indexBufferData) 
: Primitive(vertexShaderLocation,fragmentShaderLocation,vertexData,indexBufferData) {}

