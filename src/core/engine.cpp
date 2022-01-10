#include "engine.hpp"

Engine::Engine() 
{
    deltaTime =0;
    fpsLimit = 1.0 / 60.0;
    lastFrameTime =0;
}

Engine::~Engine() 
{
    
}

void Engine::run()
{
    if(!init()){
        std::cout<<"Error while initializing!"<<std::endl;
        exit(-1);
    }
    mainLoop();
    cleanUp();

}

bool Engine::initGLFW() 
{
    glfwSetErrorCallback(glfw_error_callback);
    if(!glfwInit()){
        return false;
    }
    window = glfwCreateWindow(engineConfig.getWindowSize().x, engineConfig.getWindowSize().y, "DEngine", NULL, NULL);
    if(!window){
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);

    monitor = glfwGetPrimaryMonitor();
    int winPos[2]={0,0};
    glfwGetWindowPos(window, &winPos[0], &winPos[1]);

    engineConfig.setWindowPos(glm::vec2(winPos[0], winPos[1]));
    return true;
}

bool Engine::initGLAD() 
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return false;
    }
    return true;
}

bool Engine::init() 
{
    if(!initGLFW()){
        std::cout << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    if (!initGLAD())
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}

void Engine::mainLoop() 
{
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();
        input();
        processEvents();
        draw();
    }
}
void Engine::cleanUp() 
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Engine::setFullScreen(bool isFullscreen) 
{
    if(!engineConfig.isFullscreen()){
    int winPos[2] = {0, 0};
    glfwGetWindowPos(window, &winPos[0], &winPos[1]);

    engineConfig.setWindowPos(glm::vec2(winPos[0], winPos[1]));

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(window,monitor,0,0, mode->width,mode->height,0);
    engineConfig.setFullscreen(true);
    }else{
        glfwSetWindowMonitor(window, nullptr, engineConfig.getWindowPos().x, engineConfig.getWindowPos().y, engineConfig.getWindowSize().x, engineConfig.getWindowSize().y, 0);
        engineConfig.setFullscreen(false);
    }
}

void Engine::setWindowSize(int width, int height) 
{
    if (!engineConfig.isFullscreen())
    {
        engineConfig.setFullscreen(false);
        engineConfig.setWindowSize(glm::vec2(width, height));
        glfwSetWindowSize(window,width,height);
    }
   
}

void glfw_error_callback(int error, const char* description) 
{
    fprintf(stderr, "Error: %s\n", description);
}

void glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

void Engine::input()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        setFullScreen(true);
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        setWindowSize(1600,900);
    }
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        setWindowSize(1000, 1000);
    }
}

void Engine::processEvents()
{
}

void Engine::draw()
{
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
