#ifndef PROGRAM_HPP_
#define PROGRAM_HPP_
#include <vector>
#include "shader.hpp"

class Program
{
private:
public:
    Program(const std::vector<Shader> &shaders);
    ~Program();
    GLuint getShaderProgramID() const;

    GLint attrib(const GLchar *attribName) const;

    GLint uniform(const GLchar *uniformName) const;

    GLuint shaderProgramID;

    Program(const Program &);
    const Program &operator=(const Program &);
};
#endif