#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>


#include "../renderer/Shader.h"

class Camera
{
public:

    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    bool firstClick = true;

    int width;
    int height;

    float speed = 1.0f;
    float sensitivity = 100.0f;

    Camera(int width, int height, glm::vec3 position);


    glm::mat4 MatrixProjection(float FOVdeg, float nearPlane, float farPlane);
    void Inputs(GLFWwindow *window, float dt);
};
#endif