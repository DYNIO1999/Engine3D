#include "shader.hpp"
#include <stdexcept>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream>

Shader::Shader(const std::string &shaderCode, GLenum shaderType) : shaderObjectId(0),
                                                                   refCounter(NULL)
{
    // create the shader object
    shaderObjectId = glCreateShader(shaderType);
    if (shaderObjectId == 0)
        throw std::runtime_error("glCreateShader failed");

    // set the source code
    const char *code = shaderCode.c_str();
    glShaderSource(shaderObjectId, 1, (const GLchar **)&code, NULL);

    // compile
    glCompileShader(shaderObjectId);

    // throw exception if compile error occurred
    GLint status;
    glGetShaderiv(shaderObjectId, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        std::string msg("Compile failure in shader:\n");

        GLint infoLogLength;
        glGetShaderiv(shaderObjectId, GL_INFO_LOG_LENGTH, &infoLogLength);
        char *strInfoLog = new char[infoLogLength + 1];
        glGetShaderInfoLog(shaderObjectId, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;

        glDeleteShader(shaderObjectId);
        shaderObjectId = 0;
        throw std::runtime_error(msg);
    }

    refCounter = new unsigned;
    *refCounter = 1;
}

Shader::Shader(const Shader &other) : shaderObjectId(other.shaderObjectId),
                                      refCounter(other.refCounter)
{
    _retain();
}

Shader::~Shader()
{
    //refCounter will be NULL if constructor failed and threw an exception
    if (refCounter)
        _release();
}

GLuint Shader::getShaderObjectID() const
{
    return shaderObjectId;
}

Shader &Shader::operator=(const Shader &other)
{
    _release();
    shaderObjectId = other.shaderObjectId;
    refCounter = other.refCounter;
    _retain();
    return *this;
}

Shader Shader::shaderFromFile(const std::string &filePath, GLenum shaderType)
{
    // open file
    std::ifstream f;
    f.open(filePath.c_str(), std::ios::in | std::ios::binary);
    if (!f.is_open())
    {
        throw std::runtime_error(std::string("Failed to open file: ") + filePath);
    }

    // read whole file into stringstream buffer
    std::stringstream buffer;
    buffer << f.rdbuf();

    // return new shader
    Shader shader(buffer.str(), shaderType);
    return shader;
}

void Shader::_retain()
{
    assert(refCounter);
    *refCounter += 1;
}

void Shader::_release()
{
    assert(refCounter && *refCounter > 0);
    *refCounter -= 1;
    if (*refCounter == 0)
    {
        glDeleteShader(shaderObjectId);
        shaderObjectId = 0;
        delete refCounter;
        refCounter = NULL;
    }
}
