#ifndef _LINE_H_
#define _LINE_H_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

class Line
{
private:
    float start_x;
    float start_y;
    float start_z;

    float end_x;
    float end_y;
    float end_z;

    glm::mat4 model;

    float *position;
    unsigned int *indices;
    unsigned int indicesCount;

    int layout;

public:
    Line(float start_x, float start_y, float start_z, float end_x, float end_y, float end_z) : start_x(start_x), start_y(start_y), start_z(start_z),
    end_x(end_x), end_y(end_y), end_z(end_z)
    {
        position = new float[6]{start_x, start_y, start_z,
             end_x, end_y, end_z};
        model = glm::translate(glm::mat4(1.0f), glm::vec3(start_x, start_y, start_z));
        indices = new unsigned int[2]{0, 1};
        indicesCount = 2;
        layout = 3;
    }
    ~Line()
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
        model = glm::translate(glm::mat4(1.0f), glm::vec3(start_x, start_y, start_z));
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
        return 6 * sizeof(float);
    }
};
#endif