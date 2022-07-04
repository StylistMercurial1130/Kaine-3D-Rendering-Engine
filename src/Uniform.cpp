#include "include/Uniform.h"

void UniformHandler::PopulateUniformDataMap(std::string uniformName,unsigned int shaderId){
    
    uniformDataMap.insert({
        uniformName,
        glGetUniformLocation(shaderId,uniformName.c_str())
    });

}

void UniformHandler::ModifyUniform1i(std::string uniformName,unsigned int shaderId,int data) {

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);

    glUniform1i(uniformDataMap[uniformName],data);

}

void UniformHandler::ModifyUniform1f(std::string uniformName,unsigned int shaderId,float data) {

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);

    glUniform1f(uniformDataMap[uniformName],data);

}

void UniformHandler::ModifyUniform2vf(std::string uniformName,unsigned int shaderId,glm::vec2 data){

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);

    glUniform2f(uniformDataMap[uniformName],data.x,data.y);

}