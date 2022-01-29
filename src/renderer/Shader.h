#ifndef _SHADER_H_
#define _SHADER_H_
#include <string>
#include <unordered_map>


#include <glm.hpp>
/**
 * @brief Struktura przetrzymujaca kody zrodlowe shaderow
 * 
 */
struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};
/**
 * @brief Klasa Shader
 * 
 */
class Shader
{
private:
    std::string FilePath; 
    unsigned int RendererID;



    std::unordered_map<std::string, int> UniformLocationCache;

    int GetUniformLocation(const std::string &name);

    ShaderProgramSource ParseShader(const std::string &filepath);
    
    unsigned int CompileShader(unsigned int type, const std::string &source);
    
    unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);

public:
    /**
     * @brief Konstruktor klasy shader tworzy nowy shader
     * 
     * @param filepath sciezka do pliku
     */
    Shader(const std::string& filepath);
    /**
     * @brief Destruktor
     * 
     */
    ~Shader();
    /**
     * @brief Metoda bindujaca shader
     * 
     */
    void Bind() const;
    /**
     * @brief Metoda unbindujaca shader
     * 
     */
    void Unbind() const;

    /**
     * @brief Ustawia wartosc dla uniformu
     * 
     * @param name nazwa zmiennej w shaderze
     * @param value przypisuje wartosc
     */
    void SetUniform1i(const std::string &name, int value);
    /**
     * @brief Ustawia wartosc dla uniformu
     *
     * @param name nazwa zmiennej w shaderze
     * @param value przypisuje wartosc
     */
    void SetUniform1f(const std::string &name, float value);
    /**
     * @brief  Ustawia wartosc dla uniformu
     *
     * @param name nazwa zmiennej w shaderze
     * @param v0  przypisuje wartosc
     * @param v1  przypisuje wartosc
     * @param v2  przypisuje wartosc
     * @param v3  przypisuje wartosc
     */
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    /**
     * @brief Ustawia wartosc dla uniformu
     *
     * @param name nazwa zmiennej w shaderze
     * @param matrix przypisuje wartosc
     */
    void SetUniformMat4f(const std::string &name, glm::mat4 matrix);
};
#endif