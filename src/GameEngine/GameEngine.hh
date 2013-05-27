#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Window.hpp>
#include "GameInformation.hh"
#include "../WorldEngine/WorldEngine.hh"
#include "../GraphicEngine/GraphicEngine.hh"
#include "../InterfaceEngine/InterfaceEngine.hh"

namespace Game
{
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
        Game::GameInformation __gameInformation;
        sf::Window* __window;
    };

}
#endif // GAMEENGINE_H

