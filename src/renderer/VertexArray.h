#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

/**
 * @brief Klasa VertexArray
 * 
 */
class VertexArray
{
private:
    unsigned int RendererID;
public:
    /**
     * @brief Konstruktor VertexArray
     * 
     */
    VertexArray();
    /**
     * @brief Destruktor VertexArray
     *
     */
    ~VertexArray();
    /**
     * @brief Metoda dodaje do VertexArray buffer i layout bufferu
     * 
     * @param vb VertexBuffer
     * @param layout VertexBufferLayout
     */
    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    /**
     * @brief Metoda Binduje VertexArray
     * 
     */
    void Bind() const;
    /**
     * @brief Metoda Unbinduje VertexArray
     *
     */
    void Unbind() const;
};
#endif