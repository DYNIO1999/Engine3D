#include <iostream>
#include <glfw3.h>
#include <glm.hpp>
#include <ext.hpp>


int main(){
    GLFWwindow *window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1600, 900, "DEngine3D", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // Vertices information
    GLfloat vertices[] = {1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1,      // (front)
                          1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, -1,      // (right)
                          1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1,      // (top)
                          -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1,  // (left)
                          -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1,  // (bottom)
                          1, -1, -1, -1, -1, -1, -1, 1, -1, 1, 1, -1}; // (back)

    // Normal information
    GLfloat normals[72] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1,      // (front)
                           1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,      // (right)
                           0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,      // (top)
                           -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0,  // (left)
                           0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0,  // (bottom)
                           0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1}; // (back)
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glNormalPointer(GL_FLOAT, 0, normals);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
        glPopMatrix();
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}