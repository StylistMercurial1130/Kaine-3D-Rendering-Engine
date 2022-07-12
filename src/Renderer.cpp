#include <iostream>
#include "include/Renderer.h"
#include "include/vertexbuffer.h"
#include "include/VertexArray.h"
#include "include/IndexBuffer.h"
#include "include/vertex.h"
#include "include/Textures.h"
#include "include/Shader.h"
#include "include/Uniform.h"
#include "include/Renderer.h"
#include "include/Primitives.h"

int Renderer::CreateWindow(const char* windowTitle,int width,int height) {

    if (!glfwInit()) return 0;
    mRendererwindow = glfwCreateWindow(width, height, "Kaine 3d renderer", NULL, NULL);
    if (!mRendererwindow) {
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(mRendererwindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return 0;
    return 1;

}

Renderer::Renderer(const char* windowTitle,int width,int height) {

    if(!CreateWindow(windowTitle,width,height)) {
        std::cout<<"dummy error message ! some thing has gone wrong, will appear till an error system has be set !" << std::endl;
        return;
    }
    std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;

}

void Renderer::Run() {

    Triangle triangle;
    triangle.BindRenderData();

    while(!glfwWindowShouldClose(mRendererwindow)) {
        glClear(GL_COLOR_BUFFER_BIT);
        /**
         *      do Some Rendering and stuff here !
         */
        glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,nullptr);
        glfwSwapBuffers(mRendererwindow);
        glfwPollEvents();
    }


}

Renderer::~Renderer() {

    glfwDestroyWindow(mRendererwindow);
    glfwTerminate();

}
