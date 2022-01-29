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
/**
 * Klasa kamera
 */
class Camera
{
public:

    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    /**
     * Zmienna przetrzymuje informacje czy odbyło się kliknięcie
     */
    bool firstClick = true;
    /**
     *parametr szerokości
     */
    int width;
    /**
     *parametr wysokości
     */
    int height;
    /**
     *parametr szybkości
     */
    float speed = 1.0f;
    /**
    *parametr czułości
    */
    float sensitivity = 100.0f;
    /**
     * @brief Construct a new Camera object
     *
     * @param width szerokość kamery
     * @param height wysokość kamery
     * @param position pozycja kamery
     */
    Camera(int width, int height, glm::vec3 position);

/**
 * @brief projekcja matrycy 
 * 
 * @param FOVdeg szerkosc przestrzeni
 * @param nearPlane zasieg bliski
 * @param farPlane zasieg daleki
 * @return glm::mat4 
 */
    glm::mat4 MatrixProjection(float FOVdeg, float nearPlane, float farPlane);
    void Inputs(GLFWwindow *window, float dt);
};
#endif