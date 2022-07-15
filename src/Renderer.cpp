#include "include/Renderer.h"
#include "include/IndexBuffer.h"
#include "include/Mesh.h"
#include "include/Primitives.h"
#include "include/Renderer.h"
#include "include/Shader.h"
#include "include/Textures.h"
#include "include/Uniform.h"
#include "include/VertexArray.h"
#include "include/vertex.h"
#include "include/vertexbuffer.h"
#include <iostream>

static std::vector<Vertex> pyramid = {
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

static std::vector<unsigned int> pyramidIndexBuffer = {
    0, 1, 2,
    3, 4, 5,
    6, 7, 8,
    9, 10, 11,
    12, 13, 14,
    15, 16, 17
};

int Renderer::CreateWindow(const char* windowTitle, int width, int height)
{
    if (!glfwInit())
        return 0;
    mRendererwindow = glfwCreateWindow(width, height, "Kaine 3d renderer", NULL, NULL);
    if (!mRendererwindow) {
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(mRendererwindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return 0;
    return 1;
}

Renderer::Renderer(const char* windowTitle, int width, int height)
{
    if (!CreateWindow(windowTitle, width, height)) {
        std::cout << "dummy error message ! some thing has gone wrong, will appear till an error system has be set !" << std::endl;
        return;
    }
    std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;
}

void Renderer::Run()
{
    UniformHandler uniformHandler;
    Shader shader("./shaders/shader.vert", "./shaders/shader.frag");
    Mesh pyramidMesh(pyramid, pyramidIndexBuffer);
    pyramidMesh.AddTextures("./textures/brick_wall.jpg", 0);
    pyramidMesh.BindMeshTextures(0, uniformHandler, shader);
    shader.UseShaderProgram();  
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(mRendererwindow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 proj = glm::mat4(1.0f);
        model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
        proj = glm::perspective(glm::radians(45.0f), (float)(800 / 800), 0.1f, 100.0f);
        uniformHandler.ModifyUniformMat4f("model", shader.GetShaderId(), model);
        uniformHandler.ModifyUniformMat4f("view", shader.GetShaderId(), view);
        uniformHandler.ModifyUniformMat4f("proj", shader.GetShaderId(), proj);
        pyramidMesh.Draw();
        glfwSwapBuffers(mRendererwindow);
        glfwPollEvents();
    }
}

Renderer::~Renderer()
{

    glfwDestroyWindow(mRendererwindow);
    glfwTerminate();
}
