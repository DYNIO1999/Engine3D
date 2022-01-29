#ifndef _VERTEX_LAYOUT_BUFFER_H_
#define _VERTEX_LAYOUT_BUFFER_H_
#include <vector>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int GetSizeType(unsigned int type){
        switch (type)
        {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1; 
        }
        return 0;
    }
    
};


class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;
public:
    VertexBufferLayout() : stride(0){

    }
    ~VertexBufferLayout(){
        elements.clear();
    }

    template <typename T>
    void Push(unsigned int count);

    const std::vector<VertexBufferElement>&  GetElements() const { return elements;}
    unsigned int GetStride() const { return stride; }
};
#endif