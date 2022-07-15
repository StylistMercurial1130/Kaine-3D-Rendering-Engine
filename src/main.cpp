#include "include/Renderer.h"
#include <iostream>
#include <vector>

int main(void)
{

    Renderer* renderer = new Renderer("kaine 3d rendering engine", 800, 800);
    renderer->Run();

    return 0;
}

// GLFWwindow* window;
// /* Initialize the library */
// if (!glfwInit()){
//     print("message ");
//     return -1;
// }

// /* Create a windowed mode window and its OpenGL context */
// window = glfwCreateWindow(640, 480, "Kaine 3d renderer", NULL, NULL);
// if (!window)
// {
//     glfwTerminate();
//     return -1;
// }

// /* Make the window's context current */
// glfwMakeContextCurrent(window);

// if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){

//     std :: cout << "ok something went wrong !" << std :: endl;
//     return EXIT_FAILURE;

// }

// std::cout << "OpenGL version " << glGetString(GL_VERSION) << std::endl;

// Shader shader = Shader("./shaders/shader.vert","./shaders/shader.frag");
// shader.CompileShaders();
// shader.UseShaderProgram();

// Textures textures("textures/brick_wall.jpg");

// UniformHandler uniformHandler;
// textures.BindTextures(0);
// uniformHandler.ModifyUniform1i("ourTexture",shader.GetShaderId(),0);

// std::vector<Vertex> vertices = {

//     Vertex{glm::vec3(+0.0f,+0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.5f,+1.0f)},
//     Vertex{glm::vec3(-0.5f,-0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+0.0f,+0.0f)},
//     Vertex{glm::vec3(+0.5f,-0.5f,+0.0f),glm::vec3(+0.0f,+0.0f,+0.0f),glm::vec2(+1.0f,+0.0f)}

// };

// std::vector<unsigned int> indeces = {
//     0,1,2
// };

// VertexBuffer VBO_1(vertices);
// VertexArray VAO_1;

// VAO_1.BindVertexArray();
// VAO_1.CreateLayout(3,GL_FLOAT,true,0,sizeof(Vertex),&VBO_1);
// VAO_1.CreateLayout(2,GL_FLOAT,true,24,sizeof(Vertex),&VBO_1);

// IndexBuffer IBO_1;
// IBO_1.BindIndexBuffer();
// IBO_1.PopulateIndexBuffer(indeces);

// float val = 0.001f;

// /* Loop until the user closes the window */
// while (!glfwWindowShouldClose(window))
// {
//     /* Render here */
//     glClear(GL_COLOR_BUFFER_BIT);

//     glm::mat4 trans = glm::mat4(1.0f);
//     trans = glm::translate(trans, glm::vec3(val, 0.0f, 0.0f));
//     trans = glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0.0f,0.0f,1.0f));
//     uniformHandler.ModifyUniformMat4f("translation_matrix",shader.GetShaderId(),trans);
//     val = val + 0.001f;

//     textures.BindTextures(0);
//     glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_INT,nullptr);

//     /* Swap front and back buffers */
//     glfwSwapBuffers(window);

//     /* Poll for and process events */
//     glfwPollEvents();
// }
