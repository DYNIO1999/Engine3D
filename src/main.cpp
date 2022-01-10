#include "core/engine.hpp"


int main(){
    Engine* engine;
    engine = new Engine();
    engine->run();
    delete engine;

    
}