#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "include/util.h"
#include "include/shader.h"
#include "include/vertexbuffer.h"
#include "include/vertex.h"
#include "include/VertexArray.h"
#include "include/IndexBuffer.h"

int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        print("message ");
        return -1;
    }


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Kaine 3d renderer", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

        std :: cout << "ok something went wrong !" << std :: endl;
        return EXIT_FAILURE;

    }

    Shader shader = Shader("./shaders/shader.vert","./shaders/shader.frag");
    shader.CompileShaders();
    shader.UseShaderProgram();

    std::vector<Vertex> vertices = {

        Vertex{glm::vec3(+0.0f,+1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)},
        Vertex{glm::vec3(-1.0f,-1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)},
        Vertex{glm::vec3(+1.0f,-1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)}

    };

    std::vector<unsigned int> indeces = {
        0,1,2
    };

    VertexBuffer VBO_1(vertices);
    VertexArray VAO_1;

    VAO_1.BindVertexArray();
    VAO_1.CreateLayout(3,GL_FLOAT,true,0,sizeof(Vertex),&VBO_1);

    IndexBuffer IBO_1;
    IBO_1.BindIndexBuffer();
    IBO_1.PopulateIndexBuffer(indeces);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}