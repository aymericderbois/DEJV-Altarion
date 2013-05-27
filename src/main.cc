#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "GameEngine/GameEngine.hh"

int main() {
    Game::GameEngine::getInstance().run();
    return EXIT_SUCCESS;
}
