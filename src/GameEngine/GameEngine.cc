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
        this->__window = new sf::Window(sf::VideoMode(800, 600), "Universal Supremacy");
        while (this->__window->isOpen()) {
            if (this->__gameInformation.isInGame()) {

            } else if (this->__gameInformation.isInMenu()) {

            }

            this->__window->display();
        }
    }

}