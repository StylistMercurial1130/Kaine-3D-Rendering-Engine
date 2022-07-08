#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Renderer{

public:
    
private:

    GLFWwindow* mRendererwindow;

public:

    static void RenderPrimtivesTriangle();
    static void RenderPrimitvesSquare();
    static void RenderPrimtivesCube();
    static void RenderPrimitvesSphere();
    void Run();
    Renderer(const char* windowTitle,int width,int height);
    ~Renderer();

private:
    int CreateWindow(const char* windowTitle,int width,int height);

};

#endif
