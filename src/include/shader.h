#ifndef __SHADER_H__
#define __SHADER_H__

#include "glm.hpp"
#include "glad/glad.h"
#include <iostream>
#include <map>
#include <memory>
#include <variant>


enum uniformDataType{
    VEC_1 = 1 , VEC_2 = 2, VEC_3 = 4
};

class Shader{

private:


    class Uniform{

    public:

        std::string uniformName;
        std::variant<glm::vec1,glm::vec2> uniformData;  
        uniformDataType dataType;
        int uniformId;
    
        Uniform(int id,std::string name,uniformDataType type){

            this->uniformId = id;
            this->uniformName = name;
            this->dataType = type;

        }

    };

    std::map<int,std::unique_ptr<Uniform>> uniformDataMap;    
  
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
