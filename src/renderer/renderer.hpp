#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include <iostream>
#include <sstream>
#include <fstream>
#include <ext.hpp>

#include <cassert>
#include <vector>


#include "indexbuffer.hpp"
#include "vertexarray.hpp"
#include "shader.hpp"

#define ASSERT(x) if (!(x)) __debugbreak()
#define GLCall(x) GLClearError(); x; ASSERT( GLLogCall(#x, __FILE__, __LINE__) )

static void GLClearError(){
    while(glGetError()!=GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line){
    // will print out decimal error code, but need to convert to hexadecimal to check header file errors
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "):" << function << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

class VertexArray;
class IndexBuffer;

class Renderer
{
private:

public:

    Renderer();
    ~Renderer();
    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;
    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;  
    void Clear() const;
};
#endif