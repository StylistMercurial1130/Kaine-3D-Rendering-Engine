#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

#include "glad/glad.h"
#include <vector>

class IndexBuffer{

private:

    unsigned int indexBufferObjectId;

public:

    IndexBuffer();
    void BindIndexBuffer();
    void PopulateIndexBuffer(std::vector<unsigned int>& indexElements);
    static void UnBindIndexBuffer();
    ~IndexBuffer();

};


#endif
