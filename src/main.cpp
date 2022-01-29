#include "core/engine.h"


int main(){
    Engine* engine;
    engine = new Engine();
    engine->run();
    delete engine;   
}