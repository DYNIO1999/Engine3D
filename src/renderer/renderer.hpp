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

#include "program.hpp"

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x),__FILE__,__LINE__)



static void GLClearError(){
    while(glGetError()!=GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line){

}
class Renderer
{
private:

public:
    float* verticesData;
    float* indicesData;
    Program *shaderProgram;
    std::vector<Shader> shaders;
    GLuint VAO;
    GLuint VBO;


    Renderer();
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;
    void loadShaders();


};
#endif