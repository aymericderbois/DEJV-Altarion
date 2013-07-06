#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include "../GraphicEngine/GraphicEngine.hh"
#include "GameInformation.hh"
#include "../WorldEngine/WorldEngine.hh"
#include "../GraphicEngine/InterfaceEngine.hh"
#include "../IHM/Menu.hh"

namespace Game {

    class GameEngine {
    public:
        static GameEngine& getInstance();
        GameEngine();

    public:
        void run(bool startInGame);
        void handleWindowsEvents();
        Game::GameInformation* getGameInformation();

    private:
        World::WorldEngine __world;
        GraphicEngine __graphic;
        //InterfaceEngine __interface;
        Game::GameInformation* __gameInformation;
        sf::RenderWindow* __window;
    };

}
#endif // GAMEENGINE_H

