#ifndef _TRANSFORM_
#define _TRANSFORM_

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/vector_angle.hpp>

/**
 * @brief Klasa Transform
 * 
 */
class Transform
{
private:
    
public:
    /**
    * @brief Konstruktor klasy Transform
    * 
    */
    Transform(){

    }
    /**
     * @brief Destruktor klasy Transform
     * 
     */
    ~Transform(){

    }
    /**
     * @brief Metoda zmieniajaca skale
     * 
     * @param origin startowa pozycja
     * @param scale skala
     * @return nowa macierz
     */
    glm::mat4 Scale(glm::mat4 origin, glm::vec3 scale)
    {
        return glm::scale(origin, glm::vec3(scale.x, scale.y, scale.z));
    }
    /**
     * @brief  Metoda przemieszczajaca obiekt
     *
     * @param origin startowa pozycja
     * @param move wektor przemieszczenia
     * @return nowa macierz
     */
    glm::mat4 Translate(glm::mat4 origin, glm::vec3 move)
    {
        return glm::translate(origin, glm::vec3(move.x, move.y, move.z));
    }
    /**
     * @brief Metoda obracajaca obiekt
     *
     * @param origin startowa pozycja
     * @param degrees kat o ile
     * @param direction kierunek obrotu
     * @return nowa macierz
     */
    glm::mat4 Rotate(glm::mat4 origin,  float degrees,  glm::vec3 direction){

        return glm::rotate(origin, glm::radians(degrees), direction);
    }

};
#endif