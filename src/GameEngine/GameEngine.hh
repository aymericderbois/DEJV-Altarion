#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Window.hpp>
#include "../WorldEngine/WorldEngine.hh"
#include "../GraphicEngine/GraphicEngine.hh"
#include "../InterfaceEngine/InterfaceEngine.hh"

class GameEngine
{
public:

    static GameEngine getInstance();
    GameEngine();

public:
    void run();

private:
    WorldEngine __world;
    GraphicEngine __graphic;
    InterfaceEngine __interface;
};

#endif // GAMEENGINE_H
