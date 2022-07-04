#include "include/Textures.h"

Textures::Textures(std::string path)
:filePath(path) , width(0) , height(0) , bpp(0) ,textureBuffer(nullptr){

    glGenTextures(1,&textureBufferId);
    glBindTexture(GL_TEXTURE_2D,textureBufferId); 

    stbi_set_flip_vertically_on_load(1);
    textureBuffer = stbi_load(filePath.c_str(),&width,&height,&bpp,0);

    if(textureBuffer == nullptr){
    
        std :: cout << "texture " << filePath << " not loaded !" << std::endl;
        return;
    
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,(void*)textureBuffer);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    UnbindTexture();

    stbi_image_free(textureBuffer);

}

void Textures::BindTextures(unsigned int slot) {

    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D,textureBufferId);

}

void Textures::UnbindTexture() {

    glBindTexture(GL_TEXTURE_2D,0);

}