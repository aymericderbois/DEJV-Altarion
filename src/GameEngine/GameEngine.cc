#include "GameEngine.hh"
#include "../WorldEngine/WorldEngine.hh"

namespace Game
{

    GameEngine::GameEngine()
    {
        this->__gameInformation = new GameInformation();
    }

    GameEngine GameEngine::getInstance()
    {
        static GameEngine instance;
        return instance;
    }

    void GameEngine::run()
    {
        this->__window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Universal Supremacy");
        this->__graphic.setWindow(this->__window);

        Interface::Menu menu;
        //World::WorldEngine world;
        menu.init();
        //int i = 0;
        while (this->__window->isOpen())
        {
            this->__window->clear();
            this->handleWindowsEvents(); // prevents the windows from lock-looping
            
            if (this->__gameInformation->isInGame())
            {
                this->__graphic.getInterfaceEngine().display(this->__world);
                this->__graphic.getInterfaceEngine().update(this->__world);
            }
            else if (this->__gameInformation->isInMenu())
            {
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