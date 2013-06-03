#include "GameEngine.hh"

namespace Game
{

    GameEngine::GameEngine() {
    }

    GameEngine GameEngine::getInstance() {
        static GameEngine instance;
        return instance;
    }

    void GameEngine::run() {
        this->__window = new sf::RenderWindow(sf::VideoMode(800, 600), "Universal Supremacy");
        this->__graphic.setWindow(this->__window);
        
        while (this->__window->isOpen()) {
            this->handleWindowsEvents();
            
            if (this->__gameInformation.isInGame()) {
                
            } else if (this->__gameInformation.isInMenu()) {
                this->__window->clear();
            }

            this->__window->display();
        }
    }
    
    void GameEngine::handleWindowsEvents() {
        sf::Event event;
            
        while (this->__window->pollEvent(event))
        {
            // Closing window properly
            if (event.type == sf::Event::Closed)
                this->__window->close();
        }
    }
}