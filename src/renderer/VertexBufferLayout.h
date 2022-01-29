#ifndef _VERTEX_LAYOUT_BUFFER_H_
#define _VERTEX_LAYOUT_BUFFER_H_
#include <vector>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

/**
 * @brief Struktura przetrzymujaca informacje o ulozeniu daty w VertexBufferze
 * 
 */
struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
    /**
     * @brief Metoda zwraca rozmiar typu danych
     * 
     * @param type typ 
     * @return zwraca rozmiar 
     */
    static unsigned int GetSizeType(unsigned int type){
        switch (type)
        {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1; 
        }
        return 0;
    }
    
};

/**
 * @brief Klasa przetrzymujaca informacje o ulozeniu daty w VertexBufferze
 * 
 */
class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;
public:
    /**
     * @brief Konstruktor klasy VertexBufferLayout
     * 
     */
    VertexBufferLayout() : stride(0){

    }
    /**
     * @brief Destruktor klasy VertexBufferLayout
     *
     */
    ~VertexBufferLayout(){
        elements.clear();
    }
    /**
     * @brief Template do pushowania elementow okreslajacych ulozenie danych w VertexBuffer
     * 
     * @tparam T typ
     * @param count ilosc
     */
    template <typename T>
    void Push(unsigned int count);

    /**
     * @brief Metoda zwraca obiekty elementy ulozenia danych w VertexBufferze
     * 
     * @return const std::vector<VertexBufferElement>& 
     */
    const std::vector<VertexBufferElement>&  GetElements() const { return elements;}
    /**
     * @brief Metoda zwraca rozmiar stride
     * 
     * @return unsigned int 
     */
    unsigned int GetStride() const { return stride; }
};
#endif