#ifndef _CUBE_HPP_
#define _CUBE_HPP_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>


enum  CUBE_TYPE{
    CUBE_DEFAULT,
    CUBE_DIFFERENT_COLORS,
};
/** 
 * Klasa sześcianu
 */
class Cube
{

private:
    float x;
    float y;
    float z;
    glm::mat4 model;

    float *position;
    unsigned int *indices;
    unsigned int indicesCount;

    int layout;
    int type;

/**
 * Sześcian przyjmuje wartości pozycji x,y,z oraz typ  
 * 
 */
public:
    Cube(float x, float y, float z, int type) : x(x), y(y), z(z), type(type)
    {
        if(CUBE_DEFAULT ==this->type){
        position = new float[24]{
            // front
            -1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            -1.0, 1.0, 1.0,
            // back
            -1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
            -1.0, 1.0, -1.0
        };
        }
        else if (this->type == CUBE_DIFFERENT_COLORS){
            position = new float[48]{
                // front
                -1.0, -1.0, 1.0, 1.0, 1.0, 0.0,
                1.0, -1.0, 1.0, 0.0, 1.0, 0.0,
                1.0, 1.0, 1.0, 0.0, 0.0, 1.0,
                -1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
                // back
                -1.0, -1.0, -1.0, 1.0, 0.0, 0.0,
                1.0, -1.0, -1.0, 0.0, 1.0, 0.0,
                1.0, 1.0, -1.0, 0.0, 0.0, 1.0,
                -1.0, 1.0, -1.0, 1.0, 1.0, 1.0

            };
        }
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
        indices = new unsigned int[36]{
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
        };
        indicesCount = 36;
        layout = 3;
    }
    /**
     * Destruktor sześcianu
     *usuwanie indeksu
     *usuwanie pozycji
     */
    ~Cube()
    {
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
     * Metoda sluzy do ustawiania pozycji sześcianu
     */
    void setPos(glm::vec3)
    {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
    }
    /**
     * Metoda sluzy do zliczania liczby indeksów 
     */
    unsigned int IndicesCount()
    {
        return indicesCount;
    }
    /**
     * Metoda zwraca nam pozycje bufora
     */

    float *GetBufferPosition()
    {
        return position;
    }
    /**
     * Metoda zwraca nam indeks bufora
     */
    unsigned int *GetBufferIndices()
    {
        return indices;
    }
 /**
     * Metoda zwraca nam układ
     */
    int GetLayout()
    {
        return layout;
    }
    /**
     * Metoda zwraca rozmiar bufora
     */
    unsigned int GetBufferSize()
    {

        
        if (this->type == CUBE_DIFFERENT_COLORS){
        return 48 * sizeof(float);
        }else{
        return 24 * sizeof(float);
        }
    }  
};
#endif