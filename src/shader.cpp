#include "shader.h"
#include <vector>
#include <fstream>
#include <sstream>

#define FRAGMENT_SHADER 1
#define VERTEX_SHADER 0

static const std::string ExtractShaderFromLocation(const std::string& Location);
static void CompileShader(unsigned int vertexShader, unsigned int fragmentShader,
const char* vertexShaderSource,const char* fragmetShaderSource);
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

    std::vector<const char*> shaders = {
        ExtractShaderFromLocation(vertexShaderLocation).c_str(),
        ExtractShaderFromLocation(fragmentShaderLocation).c_str()
    };

    unsigned int vertexShader , fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    CompileShader(vertexShader,fragmentShader,
    shaders[VERTEX_SHADER],shaders[FRAGMENT_SHADER]);

    shaderId = glCreateProgram();

    LinkShader(vertexShader,fragmentShader,shaderId);

}


static int CheckCompileStatus(unsigned int shader){

    int status = 0;
    glGetShaderiv(shader,GL_COMPILE_STATUS, &status);
    
    if(status == GL_FALSE){
    
        int len = 0;
        glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&len);
        std::vector<char>logMessage(len);
        glGetShaderInfoLog(shader,len,&len,&logMessage[0]);
        std::string logMessageString(logMessage.begin(),logMessage.end());
        std :: cout << logMessageString<< std::endl;
        return 0;
    
    }

    return 1;

}

static void CompileShader(unsigned int vertexShader, unsigned int fragmentShader,
const char* vertexShaderSource,const char* fragmentShaderSource){

    
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);

    glCompileShader(vertexShader);

    if(!CheckCompileStatus(vertexShader) || !CheckCompileStatus(fragmentShader)){
    
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    
    }
    
}


static int CheckLinkStatus(unsigned int shaderId){

    int status = 0;
    glGetShaderiv(shaderId,GL_LINK_STATUS, &status);
    
    if(status == GL_FALSE){
    
        int len = 0;
        glGetShaderiv(shaderId,GL_INFO_LOG_LENGTH,&len);
        std::vector<char>logMessage(len);
        glGetShaderInfoLog(shaderId,len,&len,&logMessage[0]);
        std::string logMessageString(logMessage.begin(),logMessage.end());
        std :: cout << logMessageString<< std::endl;
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

    return stream.str();

}


