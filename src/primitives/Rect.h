#ifndef _RECT_H_
#define _RECT_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>
/**
 * Klasa rekt
 */
class Rect
{

private:
    float x;
    float y;
    float z;
    glm::mat4 model;
    
    float* position;
    unsigned int* indices;
    unsigned int indicesCount;


    int layout;
    /**
     * Przyjmowanie wartości dla rekt
     *pozycja  x,y,z rekt
     */
public:
    Rect(float x, float y, float z) : x(x), y(y), z(z)
    {
        position  = new float[8] {-0.5f,-0.5f,0.5f,-0.5f,0.5f,0.5f,-0.5f,0.5f,};
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
        indices = new unsigned int[6]{
            0, 1, 2,
            2, 3, 0
        };
        indicesCount =6;
        layout = 2;
    }
    /**
     * Destruktor rekt
     *usuwanie indeksu
     *usuwanie pozycji
     */
    ~Rect(){
        delete[] indices;
        delete[] position;
    }
    /**
     *Zwracanie stworzonego modelu
     */
    glm::mat4 GetTransform()
    {
        return model;
    }
    /**
     * Metoda sluzy do ustawiania pozycji 
     */
    void setPos(glm::vec3)
    {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
    }
    /**
     * Metoda sluzy do zliczania liczby indeksów
     */
    unsigned int IndicesCount(){
        return indicesCount;
    }

    /**
     * Metoda zwraca nam pozycje bufora
     */
    float* GetBufferPosition(){
        return position;
    }
    /**
     * Metoda zwraca nam indeks bufora
     */
    unsigned int*  GetBufferIndices(){
        return indices;
    }
    /**
     * Metoda zwraca nam układ
     */
    int GetLayout(){
        return layout;
    }
    /**
     * Metoda zwraca rozmiar bufora
     */
    unsigned int GetBufferSize(){
        return 8*sizeof(float);
    }
};   
#endif