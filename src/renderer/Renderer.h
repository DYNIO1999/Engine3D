#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <iostream>

#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"


#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
x;\
ASSERT(GLLogCall(#x,__FILE__, __LINE__))


/**
 * @brief OpenGL error do czyszczenia
 * 
 */
void GLClearError();
/**
 * @brief OpenGL Error Log
 * 
 */
bool GLLogCall(const char* function, const char* file, int line);



/**
 * @brief Klasa Rendereru
 * 
 */
class Renderer
{
private:
    
public:
    /**
     * @brief Usuniecie copy constructor
     *
     */
    Renderer(const Renderer &) = delete;
    /**
     * @brief Usuniecie copy assigment operator
     *
     * @return Renderer&
     */
    Renderer &operator=(const Renderer &) = delete;

    /**
     * @brief Konstruktor Rendereru
     *
     */
    Renderer();
    /**
     * @brief Destruktor Rendereru
     *
     */
    ~Renderer();
    /**
     * @brief Metoda rysujaca
     *
     * @param va aktualny uzywany vertexarray
     * @param ib aktualny uzywany indexbuffer
     * @param shader aktualnie uzywany shader
     */
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    /**
     * @brief Metoda rysujaca z wyborem typu rysowania
     *
     * @param va aktualny uzywany vertexarray
     * @param ib aktualny uzywany indexbuffer
     * @param shader  aktualnie uzywany shader
     * @param type aktualnei uzywany typ
     */
    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader,  unsigned int type) const;
    /**
     * @brief Metoda czyszczaca ekran
     * 
     */
    void Clear() const;
};
#endif