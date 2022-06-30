#include "include/Textures.h"

Textures::Textures(std::string path)
:filePath(path) , width(0) , height(0) , bpp(0) {

    glGenTextures(1,&textureBufferId);
    glBindTexture(GL_TEXTURE_2D,textureBufferId); 

    stbi_set_flip_vertically_on_load(1);
    textureBuffer = stbi_load(filePath.c_str(),&width,&height,&bpp,4);

    glTexParameteri(textureBufferId,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(textureBufferId,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(textureBufferId,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(textureBufferId,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);

    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,textureBuffer);

}

void Textures::UnbindTexture() {

    glBindTexture(GL_TEXTURE_2D,0);

}