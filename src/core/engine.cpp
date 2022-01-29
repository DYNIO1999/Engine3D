#include "engine.h"
#include "../primitives/Rect.h"
#include "../primitives/Point.h"
#include "../primitives/Cube.h"
#include "../primitives/Line.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <ctime>
#include <cmath>

void glfw_error_callback(int error, const char *description) 
{
    fprintf(stderr, "Error: %s\n", description);
}

void glfw_framebuffer_size_callback(GLFWwindow *window, int width, int height)  
{
    glViewport(0, 0, width, height);
}

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

bool Engine::initGLAD() // inicjowanie biblioteki GLAD
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


    camera = new Camera(engineConfig.getWindowSize().x, engineConfig.getWindowSize().y ,glm::vec3(0.0f, 0.0f, 2.0f));

    



    Rect test{0, 0, 0};
    Point testPoint{-1,-1,-1};
    Cube testCube(1,1,3,CUBE_DEFAULT);
    Line testLine(0,0,0, 1,1,1);

    Cube secondCube(1,1,6,CUBE_DIFFERENT_COLORS);

    vertexArrays.push_back(new VertexArray());
    vertexBuffers.push_back(new VertexBuffer(test.GetBufferPosition(), test.GetBufferSize()));
    layouts.push_back(new VertexBufferLayout());
    layouts[0]->Push<float>(test.GetLayout());
    vertexArrays[0]->AddBuffer(*vertexBuffers[0],*layouts[0]);
    indexBuffers.push_back(new IndexBuffer(test.GetBufferIndices(), test.IndicesCount()));

    shaders.push_back(new Shader("C:\\Dev_Work\\Project_Engine3D\\Engine3D\\src\\shaders\\Basic.shader"));
    ///


    vertexArrays.push_back(new VertexArray());
    vertexBuffers.push_back(new VertexBuffer(testPoint.GetBufferPosition(), testPoint.GetBufferSize()));
    layouts.push_back(new VertexBufferLayout());
    layouts[1]->Push<float>(testPoint.GetLayout());
    vertexArrays[1]->AddBuffer(*vertexBuffers[1], *layouts[1]);
    indexBuffers.push_back(new IndexBuffer(testPoint.GetBufferIndices(), testPoint.IndicesCount()));

    vertexArrays.push_back(new VertexArray());
    vertexBuffers.push_back(new VertexBuffer(testCube.GetBufferPosition(), testCube.GetBufferSize()));
    layouts.push_back(new VertexBufferLayout());
    layouts[2]->Push<float>(testCube.GetLayout());
    vertexArrays[2]->AddBuffer(*vertexBuffers[2], *layouts[2]);
    indexBuffers.push_back(new IndexBuffer(testCube.GetBufferIndices(), testCube.IndicesCount()));

    shaders.push_back(new Shader("C:\\Dev_Work\\Project_Engine3D\\Engine3D\\src\\shaders\\Second.shader"));

    vertexArrays.push_back(new VertexArray());
    vertexBuffers.push_back(new VertexBuffer(secondCube.GetBufferPosition(), secondCube.GetBufferSize()));
    layouts.push_back(new VertexBufferLayout());
    layouts[3]->Push<float>(secondCube.GetLayout());
    layouts[3]->Push<float>(secondCube.GetLayout());
    vertexArrays[3]->AddBuffer(*vertexBuffers[3], *layouts[3]);
    indexBuffers.push_back(new IndexBuffer(secondCube.GetBufferIndices(), secondCube.IndicesCount()));

    vertexArrays.push_back(new VertexArray());
    vertexBuffers.push_back(new VertexBuffer(testLine.GetBufferPosition(), testLine.GetBufferSize()));
    layouts.push_back(new VertexBufferLayout());
    layouts[4]->Push<float>(testLine.GetLayout());
    vertexArrays[4]->AddBuffer(*vertexBuffers[4], *layouts[4]);
    indexBuffers.push_back(new IndexBuffer(testLine.GetBufferIndices(), testLine.IndicesCount()));


    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        input();
        processEvents();
        shaders[0]->Bind();
        shaders[0]->SetUniformMat4f("u_MVP", CameraProjection * test.GetTransform());
        shaders[0]->SetUniform4f("u_Color", 1.0f, 0.3f, 0.8f, 1.0f); 
        
        render.Clear();
        
        render.Draw(*vertexArrays[0], *indexBuffers[0], *shaders[0]);

        shaders[0]->SetUniformMat4f("u_MVP", CameraProjection * testPoint.GetTransform());
        shaders[0]->SetUniform4f("u_Color", 0.5f, 0.7f, 0.8f, 1.0f);

        render.Draw(*vertexArrays[1], *indexBuffers[1], *shaders[0],GL_POINTS);


        

        shaders[0]->SetUniformMat4f("u_MVP", CameraProjection * testCube.GetTransform());
        shaders[0]->SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
        render.Draw(*vertexArrays[2], *indexBuffers[2], *shaders[0]);

        shaders[0]->SetUniformMat4f("u_MVP", CameraProjection * testLine.GetTransform());
        shaders[0]->SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
        render.Draw(*vertexArrays[4], *indexBuffers[4], *shaders[0], GL_LINES);

        shaders[0]->Unbind();
    
        shaders[1]->Bind();
        shaders[1]->SetUniformMat4f("u_MVP", CameraProjection * transform.Translate(secondCube.GetTransform(), glm::vec3(0, 3, 0)) * transform.Rotate(secondCube.GetTransform(), 45, glm::vec3(0,1,1)) * transform.Scale(secondCube.GetTransform(), glm::vec3(1, 2, 1)));

        render.Draw(*vertexArrays[3], *indexBuffers[3], *shaders[1]);
        shaders[1]->Unbind();

        GLCall(glfwSwapBuffers(window));
        GLCall(glfwPollEvents());
    }



}
void Engine::cleanUp() 
{
    for (auto it = vertexBuffers.begin(); it < vertexBuffers.end(); it++)
    {
        delete *it;
    }
    for (auto it = layouts.begin(); it < layouts.end(); it++)
    {
        delete *it;
    }
    for (auto it = indexBuffers.begin(); it < indexBuffers.end(); it++)
    {
        delete *it;
    }
    for (auto it = vertexArrays.begin(); it < vertexArrays.end();it++){
        delete *it;
    }
    for (auto it = shaders.begin(); it < shaders.end(); it++)
    {
        delete *it;
    }

    vertexArrays.clear();
    vertexBuffers.clear();
    layouts.clear();
    indexBuffers.clear();
    shaders.clear();
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

    camera->Inputs(window, deltaTime);
}

void Engine::processEvents()
{
    CameraProjection = camera->MatrixProjection(45.0f, 0.0f, 100.0f);
}
