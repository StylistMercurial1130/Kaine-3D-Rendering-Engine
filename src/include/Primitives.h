#ifndef __PRIMITIVES_H__
#define __PRIMITIVES_H__

#include <memory>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "vertexbuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "vertex.h"
#include "Textures.h"
#include "Shader.h"
#include "Uniform.h"
#include <vector>

class Primitive {
protected:
	VertexBuffer				mVertexbuffer;
	VertexArray					mVertexarray;
	IndexBuffer					mIndexbuffer;
	std::vector<Vertex>			mVertexdata;
	std::vector<unsigned int>	mIndexBufferLayout;
	Shader						mShader;
private:
	void SetupPrimitive(std::vector<Vertex>&,std::vector<unsigned int>&);
public:
	Primitive(std::vector<Vertex>&,std::vector<unsigned int>&);
	Primitive(const std::string& ,const std::string&,std::vector<Vertex>&,std::vector<unsigned int>&); 	
	void BindRenderData();
};

class Triangle : public Primitive {
public:
	Triangle();
	Triangle(const std::string&,const std::string&,std::vector<Vertex>&,std::vector<unsigned int>&);
}; 

class Square : public Primitive {
public:
	Square();
	Square(const std::string&,const std::string&,std::vector<Vertex>&,std::vector<unsigned int>&);
};

#endif
