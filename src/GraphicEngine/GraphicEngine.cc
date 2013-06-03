#include "GraphicEngine.hh"

GraphicEngine::GraphicEngine() {
}

void GraphicEngine::setWindow(sf::RenderWindow* window) {
    this->__window = window;
}

sf::RenderWindow* GraphicEngine::getWindow() {
    return this->__window;
}