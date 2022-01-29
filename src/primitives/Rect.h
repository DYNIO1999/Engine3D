#ifndef _RECT_H_
#define _RECT_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

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
    ~Rect(){
        delete[] indices;
        delete[] position;
    }
    glm::mat4 GetTransform()
    {
        return model;
    }
    void setPos(glm::vec3)
    {
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
    }

    unsigned int IndicesCount(){
        return indicesCount;
    }

    float* GetBufferPosition(){
        return position;
    }

    unsigned int*  GetBufferIndices(){
        return indices;
    }

    int GetLayout(){
        return layout;
    }

    unsigned int GetBufferSize(){
        return 8*sizeof(float);
    }
};   
#endif