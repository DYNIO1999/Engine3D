#include "program.hpp"
#include <stdexcept>

Program::Program(const std::vector<Shader> &shaders) : shaderProgramID(0)
{
    if (shaders.size() <= 0)
        throw std::runtime_error("No shaders were provided to create the program");

    // create the program object
    shaderProgramID = glCreateProgram();
    if (shaderProgramID == 0)
        throw std::runtime_error("glCreateProgram failed");

    // attach all the shaders
    for (unsigned i = 0; i < shaders.size(); ++i)
        glAttachShader(shaderProgramID, shaders[i].getShaderObjectID());

    // link the shaders together
    glLinkProgram(shaderProgramID);

    // detach all the shaders
    for (unsigned i = 0; i < shaders.size(); ++i)
        glDetachShader(shaderProgramID, shaders[i].getShaderObjectID());

    // throw exception if linking failed
    GLint status;
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        std::string msg("Program linking failure: ");

        GLint infoLogLength;
        glGetProgramiv(shaderProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
        char *strInfoLog = new char[infoLogLength + 1];
        glGetProgramInfoLog(shaderProgramID, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;

        glDeleteProgram(shaderProgramID);
        shaderProgramID = 0;
        throw std::runtime_error(msg);
    }
}

Program::~Program()
{
    // might be 0 if ctor fails by throwing exception
    if (shaderProgramID != 0)
        glDeleteProgram(shaderProgramID);
}

GLuint Program::getShaderProgramID() const
{
    return shaderProgramID;
}

GLint Program::attrib(const GLchar *attribName) const
{
    if (!attribName)
        throw std::runtime_error("attribName was NULL");

    GLint attrib = glGetAttribLocation(shaderProgramID, attribName);
    if (attrib == -1)
        throw std::runtime_error(std::string("Program attribute not found: ") + attribName);

    return attrib;
}

GLint Program::uniform(const GLchar *uniformName) const
{
    if (!uniformName)
        throw std::runtime_error("uniformName was NULL");

    GLint uniform = glGetUniformLocation(shaderProgramID, uniformName);
    if (uniform == -1)
        throw std::runtime_error(std::string("Program uniform not found: ") + uniformName);

    return uniform;
}