#ifndef SHADER_HPP_
#define SHADER_HPP_
#include <string>
#include "glad/glad.h"
class Shader
{
private:
    GLuint shaderObjectId;
    unsigned int* refCounter;

    void _retain();
    void _release();

public:
    Shader(const Shader &other);
    ~Shader();
    Shader &operator=(const Shader &other);
    
    GLuint getShaderObjectID() const;
    Shader(const std::string &shaderCode, GLenum shaderType);

    static Shader shaderFromFile(const std::string &filePath, GLenum shaderType);
};
#endif