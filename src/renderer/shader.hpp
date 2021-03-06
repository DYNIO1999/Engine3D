#ifndef _SHADER_HPP_
#define _SHADER_HPP_

#include <string>
#include <unordered_map>
#include "glm.hpp"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::string m_FilePath; // for debugging
    unsigned int m_RendererId;
    // caching for uniforms
    std::unordered_map<std::string, int> m_UniformLocationCache;

    int GetUniformLocation(const std::string &name);

    ShaderProgramSource ParseShader(const std::string &filepath);
    unsigned int CompileShader(unsigned int type, const std::string &source);
    unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

public:
    Shader(const std::string &filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    // set uniforms
    void SetUniform1i(const std::string &name, int value);
    void SetUniform1f(const std::string &name, float value);
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(const std::string &name, glm::mat4 matrix);

    // TODO: implement all possible (matrices, etc)
};

#endif