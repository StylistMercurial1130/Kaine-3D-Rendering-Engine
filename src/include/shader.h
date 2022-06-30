#ifndef __SHADER_H__
#define __SHADER_H__

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>

class Shader{

private:
    unsigned int shaderId;
    const std::string vertexShaderLocation , fragmentShaderLocation;
    std :: string vertexShaderSource , fragmentShaderSource;

public:

    Shader(const std::string& vertexShaderLocation,const std::string& fragmentShaderLocation);
    void CompileShaders();
    static void ClearShaderProgram();
    void UseShaderProgram();
    ~Shader();

};

#endif
