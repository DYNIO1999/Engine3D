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

//#define ASSERT
class Renderer
{
private:

public:
    float* verticesData;
    float* indicesData;
    
    std::vector<Shader> shaders;
    Renderer(){
        Program *shaderProgram = NULL;
        GLuint VAO = 0;
        GLuint VBO = 0;
    }
    ~Renderer();

    Renderer(const Renderer &) = delete;
    Renderer &operator=(const Renderer &) = delete;
    void loadShaders();
    void draw();

    void bind(float* vertices);
    void unbind();

};
#endif