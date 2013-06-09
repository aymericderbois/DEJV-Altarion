#include "GraphicEngine.hh"

GraphicEngine::GraphicEngine() {
}


void GraphicEngine::setWindow(sf::RenderWindow* window) {
    this->__window = window;
}

sf::RenderWindow* GraphicEngine::getWindow() {
    return this->__window;
}

sf::RenderWindow* GraphicEngine::GetWindow() const {
    return __window;
}

void GraphicEngine::SetWindow(sf::RenderWindow* __window) {
    this->__window = __window;

}