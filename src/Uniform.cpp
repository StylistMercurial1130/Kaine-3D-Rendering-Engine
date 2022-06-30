#include "include/Uniform.h"

void UniformHandler::PopulateUniformDataMap(std::string uniformName,unsigned int shaderId){
    
    uniformDataMap.insert({
        uniformName,
        glGetUniformLocation(shaderId,uniformName.c_str())
    });

}

template<>
void UniformHandler::ModifyUniform<glm::vec3>(std::string uniformName,unsigned int shaderId,glm::vec3& data){

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);

    glUniform3f(uniformDataMap[uniformName],data.x,data.y,data.z);

}

template<>
void UniformHandler::ModifyUniform<glm::vec2>(std::string uniformName,unsigned int shaderId,glm::vec2& data){

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);
    
    glUniform2f(uniformDataMap[uniformName],data.x,data.y);

}

template<>
void UniformHandler::ModifyUniform<glm::vec1>(std::string uniformName,unsigned int shaderId,glm::vec1& data){

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);
    
    glUniform1f(uniformDataMap[uniformName],data.x);

}

template<>
void UniformHandler::ModifyUniform<glm::vec4>(std::string uniformName,unsigned int shaderId,glm::vec4& data){

    if(uniformDataMap.find(uniformName) == uniformDataMap.end())
        PopulateUniformDataMap(uniformName,shaderId);

    glUniform4f(uniformDataMap[uniformName],data.x,data.y,data.z,data.r);

}