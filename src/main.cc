#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "GameEngine/GameEngine.hh"
#include "Tools/Textures.hh"

int main() {
    Textures::getInstance().loadAllTextures();
    Game::GameEngine::getInstance().run();
    return EXIT_SUCCESS;
}
