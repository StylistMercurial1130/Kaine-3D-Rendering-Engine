#ifndef __UNIFORM_H__
#define __UNIFORM_H__

#include <map>
#include <variant>
#include <iostream>
#include <map>
#include "glm/glm.hpp"
#include "glad/glad.h"

class UniformHandler{

private:

    std::map<std::string,int> uniformDataMap;
    
public:

    template<typename T>
    void ModifyUniform(std::string uniformName,unsigned int shaderId,T& data);

private:

    void PopulateUniformDataMap(std::string uniformName,unsigned int shaderId);

};


#endif