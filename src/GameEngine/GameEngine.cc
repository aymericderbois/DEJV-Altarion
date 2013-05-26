#include "GameEngine.hh"

GameEngine::GameEngine() {
}

GameEngine GameEngine::getInstance() {
    static GameEngine instance;
    return instance;
}

void GameEngine::run() {
    sf::Window window(sf::VideoMode(800, 600), "My window");
    while (window.isOpen()) {

        window.display();
    }
}
