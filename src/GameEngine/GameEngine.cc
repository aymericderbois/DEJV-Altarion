#include <math.h>

#include "GameEngine.hh"
#include "../WorldEngine/WorldEngine.hh"

namespace Game
{

    GameEngine::GameEngine()
    {
        this->__gameInformation = new GameInformation();
    }

    GameEngine& GameEngine::getInstance() {
        static GameEngine instance;
        return instance;
    }

    void GameEngine::run(bool startInGame)
    {
        this->__window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Universal Supremacy");
        this->__graphic.setWindow(this->__window);

        if (startInGame) {
            this->__gameInformation->setCurrentPage(Pages::IN_GAME);
        }
        
        Interface::Menu menu;
        menu.setMusic("starcraft_ambient");
        menu.getMusic()->play();
        menu.getMusic()->setVolume(60);
        //World::WorldEngine world;
        World::WorldEngine world;
        world.setMusic("sw_ambient");
        bool isFirstLoopOnWorld = true;
        menu.init();
        //int i = 0;

        this->__window->setFramerateLimit(30);
        while (this->__window->isOpen())
        {
            this->__window->clear();
            this->handleWindowsEvents(); // prevents the windows from lock-looping
            if (this->__gameInformation->isInGame()) {
                if (isFirstLoopOnWorld) {
                    isFirstLoopOnWorld = false;
                    world.init();
                    menu.getMusic()->stop();
                    world.getMusic()->play();
                    world.getMusic()->setVolume(60);
                    std::cout << "Init World" << std::endl;
                }
                this->__graphic.getInterfaceEngine().display(world);
                this->__graphic.getInterfaceEngine().update(world);
            } else if (this->__gameInformation->isInMenu()) {
                this->__graphic.getInterfaceEngine().display(menu);
                this->__graphic.getInterfaceEngine().update(menu);
            }
            this->__window->display();
        }
    }

    void GameEngine::handleWindowsEvents()
    {
        sf::Event event;

        while (this->__window->pollEvent(event))
        {
            // Closing window properly
            if (event.type == sf::Event::Closed)
                this->__window->close();
        }
    }

    Game::GameInformation* GameEngine::getGameInformation()
    {
        return __gameInformation;
    }
}