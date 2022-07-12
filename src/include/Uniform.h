#ifndef __UNIFORM_H__
#define __UNIFORM_H__

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <map>
#include <variant>


class UniformHandler {

private:
    std::map<std::string, int> uniformDataMap;

public:
    void ModifyUniform3vf(std::string name, unsigned int shaderId, glm::vec3 data);
    void ModifyUniform2vf(std::string name, unsigned int shaderId, glm::vec2 data);
    void ModifuUniform4vf(std::string name, unsigned int shaderId, glm::vec4 data);
    void ModifyUniform1f(std::string name, unsigned int shaderId, float data);
    void ModifyUniform1i(std::string name, unsigned int shaderId, int data);
    void ModifyUniformMat4f(std::string name, unsigned int shaderId, glm::mat4& data);

private:
    void PopulateUniformDataMap(std::string uniformName, unsigned int shaderId);
};

#endif