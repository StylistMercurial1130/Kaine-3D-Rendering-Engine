#ifndef __TEXTURES_H__
#define __TEXTURES_H__

#include "stb_image.h"
#include "glad/glad.h"
#include <iostream>

class Textures{

private:

    unsigned int textureBufferId;
    std::string filePath;
    unsigned char* textureBuffer;
    int width , height;
    int bpp;

public:

    Textures(std::string path);
    void BindTextures(unsigned int slot);
    static void UnbindTexture();

};

#endif

