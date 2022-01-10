#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <glm.hpp>
#include <ext.hpp>
#include <vector>



class EngineConfig{

    public:
    EngineConfig()
    {
        windowSize = glm::vec2(1600,900);
        windowPos =  glm::vec2(0,0);
        isfullscreen =false;
        iswindowedMode =false;
    }
    ~EngineConfig(){

    }


    glm::vec2 getWindowSize(){
        return windowSize;
    }
    void setWindowSize(glm::vec2 winsize){
        windowSize =winsize;
    }

    bool isFullscreen(){
        return isfullscreen;
    }
    void setFullscreen(bool fullscreen){
        isfullscreen =fullscreen;
    }

    bool isWindowedMode(){
        return iswindowedMode;
    }
    void setWindowedMode(bool windowedMode){
        iswindowedMode = windowedMode;
    }

    glm::vec2 getWindowPos()
    {
        return windowPos;
    }
    void setWindowPos(glm::vec2 winpos)
    {
        windowPos = winpos;
    }

    private:
    glm::vec2 windowSize;
    glm::vec2 windowPos;
    bool isfullscreen;
    bool iswindowedMode;
};

void glfw_error_callback(int error, const char *description);
void glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height);

class Engine
{
private:
    bool initGLFW();
    bool initGLAD();
    bool init();

    void mainLoop();

    void input();
    void processEvents();
    void draw();

    void cleanUp();


    void setFullScreen(bool isFullscreen);
    void setWindowSize(int width, int height);

public:
    EngineConfig engineConfig;
    GLFWwindow* window;
    GLFWmonitor* monitor;

    float deltaTime;
    float lastFrame;
    double fpsLimit;
    double lastFrameTime;

    Engine();
    ~Engine();
    
    Engine(const Engine &) = delete;
    Engine &operator=(const Engine &) = delete;


    void run();
};
#endif
