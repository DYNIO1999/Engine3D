#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

/**
 * @brief Klasa VertexBuffer
 * 
 */
class VertexBuffer
{
private:
    unsigned int RendererID;
public:
    /**
     * @brief Konstruktor VertexBuffer
     * 
     * @param data wskaznik na date czyli buffer
     * @param size wielkosc daty 
     */
    VertexBuffer(const void* data, unsigned int size);
    /**
     * @brief Destruktor VertexBuffer
     * 
     */
    ~VertexBuffer();
    /**
     * @brief Metoda bindujaca VertexBuffer
     * 
     */
    void Bind() const;
    /**
     * @brief Metoda unbindujaca VertexBuffer
     * 
     */
    void Unbind() const ;
};
#endif