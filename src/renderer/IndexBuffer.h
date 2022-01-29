#ifndef _INDEX_BUFFER_H_
#define _INDEX_BUFFER_H_

/**
 * @brief Klasa IndexBuffer
 * 
 */
class IndexBuffer
{
private:
    unsigned int RendererID;
    unsigned int Count;
public:
    /**
     * @brief Konstruktor klasy IndexBuffer
     * 
     * @param data wskaznik na tablice indeksow
     * @param count ilosc indeksow 
     */
    IndexBuffer(const unsigned int* data, unsigned int count);
    /**
     * @brief Destruktor klasy IndexBuffer
     * 
     */
    ~IndexBuffer();
    /**
     * @brief Metoda Bind sluzy do bindowania IndexBuffer
     * 
     */
    void Bind() const;
    /**
     * @brief Metoda UnBind sluzy do unbindowania IndexBuffer
     *
     */
    void Unbind() const;
    /**
     * @brief Wysyla ilosc ideksow
     * 
     * @return ilosc indeksow 
     */
    unsigned int GetCount() const {return Count;};
};
#endif