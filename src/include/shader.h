#ifndef __SHADER_H__
#define __SHADER_H__

#include "glad/glad.h"
#include <iostream>

class Shader{

private:

    unsigned int shaderId;
    const std::string vertexShaderLocation , fragmentShaderLocation;

public:

    Shader(const std::string& vertexShaderLocation,const std::string& fragmentShaderLocation);
    void CompileShaders();
    static void ClearShaderProgram();
    void UseShaderProgram();

};

#endif
