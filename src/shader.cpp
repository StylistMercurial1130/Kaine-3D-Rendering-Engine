#include "shader.h"
#include <vector>
#include <fstream>
#include <sstream>

static const std::string ExtractShaderFromLocation(const std::string& Location);
static void CompileShader(unsigned int vertexShader, unsigned int fragmentShader,
std::string& vertexShaderSource,std::string& fragmetShaderSource);
static int CheckCompileStatus(unsigned int shader);
static void LinkShader(unsigned int vertexShader,unsigned int fragmentShader,unsigned int shaderId);
static int CheckLinkStatus(unsigned int shaderId);

void Shader::ClearShaderProgram(){glUseProgram(0);}

void Shader::UseShaderProgram(){glUseProgram(shaderId);}

Shader::Shader(const std::string& vShaderLocation,const std::string& fShaderLocation)
: vertexShaderLocation(vShaderLocation) , fragmentShaderLocation(fShaderLocation){

    CompileShaders();

}

Shader::~Shader(){ glDeleteProgram(shaderId); }

void Shader::CompileShaders(){

    vertexShaderSource = ExtractShaderFromLocation(vertexShaderLocation);
    fragmentShaderSource = ExtractShaderFromLocation(fragmentShaderLocation);

    unsigned int vertexShader , fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    CompileShader(vertexShader,fragmentShader,
    vertexShaderSource,fragmentShaderSource);

    shaderId = glCreateProgram();

    LinkShader(vertexShader,fragmentShader,shaderId);

}


static int CheckCompileStatus(unsigned int shader){

    int status;
    glGetShaderiv(shader,GL_COMPILE_STATUS, &status);
    
    if(status != GL_TRUE){
    
        std::cout << "SHADER ERROR : COMPILE" << '\n';
        int len = 0;
        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&len);
        char* message = (char*)alloca(len * sizeof(char));
        glGetShaderInfoLog(shader,len,&len,message);
        std :: cout << message << '\n';
        return 0;
    
    }

    return 1;

}

static void CompileShader(unsigned int vertexShader, unsigned int fragmentShader,
std::string& vertexShaderSource,std::string& fragmentShaderSource){

    const char* _vertexShaderSource = vertexShaderSource.c_str();
    const char* _fragmentShaderSource = fragmentShaderSource.c_str();
    
    glShaderSource(vertexShader,1,&_vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    glShaderSource(fragmentShader,1,&_fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);

    if(!CheckCompileStatus(vertexShader) || !CheckCompileStatus(fragmentShader)){
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
    }
    
}


static int CheckLinkStatus(unsigned int shaderId){

    int status;
    glGetProgramiv(shaderId,GL_LINK_STATUS, &status);
    
    if(status != GL_TRUE){
    
        std :: cout << "SHADER ERROR : LINK " << '\n';
        int len = 0;
        glGetProgramiv(shaderId,GL_INFO_LOG_LENGTH,&len);
        char* message = (char*)alloca(len * sizeof(char));
        glGetShaderInfoLog(shaderId,len,&len,message);
        std :: cout << message << '\n';
        return 0;

    }

    return 1;

}

static void LinkShader(unsigned int vertexShader,unsigned int fragmentShader,unsigned int shaderId){

    glAttachShader(shaderId,vertexShader);
    glAttachShader(shaderId,fragmentShader);

    glLinkProgram(shaderId);

    if(!CheckLinkStatus(shaderId)){
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        glDeleteProgram(shaderId);

    }

}


static const std::string ExtractShaderFromLocation(const std::string& Location){

    std::ifstream reader(Location,std::ios::binary);
    std::string line;
    std::stringstream stream;

    while(std::getline(reader,line)){
        stream << line << '\n';
    }


    reader.close();

    return stream.str();


}


