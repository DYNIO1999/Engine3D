#ifndef ENGINE_H_
#define ENGINE_H_
#include <vector>
#include "../renderer/Renderer.h"
#include "../camera/Camera.h"
#include "../transforms/Transform.h"

/**
*Engine config przetrzymuje infomracje na temat okna 
**/
class EngineConfig{

public:
    /**
     *Configuracja okna pozycja, rozmiar
     **/
    EngineConfig()
    {
        windowSize = glm::vec2(1600,900);
        windowPos =  glm::vec2(0,0);
        isfullscreen =false;
        iswindowedMode =false;
    }
    /**
     *Destruktor konfiguracji okna 
     **/
    ~EngineConfig(){

    }


    glm::vec2 getWindowSize(){
        return windowSize;
    }
/**
 * @brief Set the Window Size object
 * 
 * @param winsize 
 */
    void setWindowSize(glm::vec2 winsize){
        windowSize =winsize;
    }
    /**
     * kurde nie wiem :(((( 
     */

    bool isFullscreen(){
        return isfullscreen;
    }
    /**
     * Metoda sluzy do ustawiania pelnego ekranu
     */
    void setFullscreen(bool fullscreen){
        isfullscreen =fullscreen;
    }

    bool isWindowedMode(){
        return iswindowedMode;
    }
    /**
     * Metoda sluzy do ustawiania trybu pelnego ekranu
     */
    void setWindowedMode(bool windowedMode){
        iswindowedMode = windowedMode;
    }
   

    glm::vec2 getWindowPos()
    {
        return windowPos;
    }
    /**
     * Metoda sluzy ustawiania pozycji okna
     */
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

/** Core
 * Klasa silnika
 * Glowny core aplikacji
 */

class Engine
{
private:
    bool initGLFW(); //inicjacja biblioteki GLFW
    bool initGLAD(); // inicjacja biblioteki GLAD
    bool init();
    /**
     * Metoda do petli gry
     *
     */
    void mainLoop();
    /**
     * Metoda do inicjacji okna
     */
    void input();
    /**
     * Metoda sluzy do pobierania inputu i przeprowadzania update na podstawie odebranych danych
     */
    void processEvents();
    /**
     * Glowny core aplikacji
     */
    void cleanUp();

    /**
     * Metoda sluzy do ustawiania pelnego ekranu
     * \param fullscreen zmienna boolowska okreslajaca czy ustawic fullscreen czy nie
     */
    void setFullScreen(bool isFullscreen);
    

    /**
     * @brief Set the Window Size object
     * 
     * @param width szerokosc
     * @param height wysokosc
     */
    void setWindowSize(int width, int height);

    /**
     * @brief Callback do GLFW ustawiajacy myszke
     * 
     * @param window wskaznik na window
     * @param xposIn pozycja myszki x
     * @param yposIn pozycja myszki y
     */
    void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

    /**
     * @brief Callback do GLFW odnosnie scrolla
     *
     * @param window wskaznik na window
     * @param xposIn pozycja myszki scroll x
     * @param yposIn pozycja myszki scroll y
     */

    void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

public:
    /**
     * @brief Obiekt konfiguracji silnika
     * 
     */
    EngineConfig engineConfig;
    /**
     * @brief Wskaznik na okno
     * 
     */
    GLFWwindow* window;
    /**
     * @brief Wskaznik na monitor
     * 
     */
    GLFWmonitor* monitor;

    /**
     * deltatime
     */
    float deltaTime;
    /**
     * Indeks klatki końcowej przedziału
     */
    float lastFrame;
    /**
     * fps
     */
    double fpsLimit;
     /**
     * odmierzanie klatki końcowej 
     */
    double lastFrameTime;


    /**
     * @brief Konstruktor silnika 
     * 
     */
    Engine();
    /**
     * @brief Destruktor silnika
     * 
     */
    ~Engine();
    /**
     * @brief Usuniecie copy constructor
     * 
     */
    Engine(const Engine &) = delete;
    /**
     * @brief Usuniecie copy assigment operator
     * 
     * @return Engine& 
     */
    Engine &operator=(const Engine &) = delete;
    /**
     * @brief Glowna metoda silnika
     * 
     */
    void run();
    /**
     * @brief Render
     * 
     */
    Renderer render;
    /**
     * @brief Kamera
     * 
     */
    Camera* camera;
    /**
     * @brief Projekcja kamery
     * 
     */
    glm::mat4 CameraProjection;
    /**
     * @brief Kontener typu wektor przetrzymujacy wskazniki na obiekty typu shader
     * 
     */
    std::vector<Shader*> shaders;
    /**
     * @brief Kontener typu wektor przetrzymujacy wskazniki na obiekty VertexArray
     *
     */
    std::vector<VertexArray*> vertexArrays;
    /**
     * @brief Kontener typu wektor przetrzymujacy wskazniki na obiekty VertexBuffer
     *
     */
    std::vector<VertexBuffer*> vertexBuffers;
    /**
     * @brief Kontener typu wektor przetrzymujacy wskazniki na obiekty VertexBufferLayout
     *
     */
    std::vector<VertexBufferLayout*> layouts;
    /**
     * @brief Kontener typu wektor przetrzymujacy wskazniki na obiekty IndexBuffer
     *
     */
    std::vector<IndexBuffer*> indexBuffers;

    /**
     * @brief Obiekt transformacja
     * 
     */
    Transform transform;
};
#endif
