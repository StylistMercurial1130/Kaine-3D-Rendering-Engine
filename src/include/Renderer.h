#ifndef __RENDERER_H__
#define __RENDERER_H__
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Renderer {
public:
    Renderer(const char* windowTitle, int width, int height);
    void Run();
    ~Renderer();

private:
    int CreateWindow(const char* dowTitle, int width, int height);

public:
    GLFWwindow* mRendererwindow;
};

#endif
