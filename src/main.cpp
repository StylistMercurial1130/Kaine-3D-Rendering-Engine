#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "include/util.h"
#include "include/shader.h"
#include "include/vertexbuffer.h"
#include "include/vertex.h"

int main(void)
{


    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()){
        print("message ");
        return -1;
    }


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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

    std::vector<Vertex> vertices = {

        Vertex{glm::vec3(+0.0f,+1.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)},
        Vertex{glm::vec3(-0.1f,+0.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)},
        Vertex{glm::vec3(+0.1f,+0.0f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f)}

    };

    VertexBuffer VBO_1(vertices);

    


    Shader shader = Shader("shaders/shader.vert","shaders/shader.frag");
    shader.UseShaderProgram();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}