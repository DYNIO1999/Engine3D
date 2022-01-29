#ifndef _POINT_H_
#define _POINT_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

class Point
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
public:
    Point(float x, float y, float z) : x(x), y(y), z(z)
    {
        position = new float[3]{ 0.0f,0.0f,0.0f};
        model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
        indices = new unsigned int[1]{0};
        indicesCount = 1;
        layout = 3;
    }
    ~Point()
    {
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

    unsigned int IndicesCount()
    {
        return indicesCount;
    }

    float *GetBufferPosition()
    {
        return position;
    }

    unsigned int *GetBufferIndices()
    {
        return indices;
    }

    int GetLayout()
    {
        return layout;
    }

    unsigned int GetBufferSize()
    {
        return 3 * sizeof(float);
    }
};
#endif