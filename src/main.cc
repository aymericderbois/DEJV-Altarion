#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "GameEngine/GameEngine.hh"
#include "Tools/Textures.hh"
#include "Tools/Sounds.hh"

int main(int argc, char *argv[]) {
    bool startInGame = false;
    if (argc == 2) {
        startInGame = true;
    }

    Textures::getInstance().loadAllTextures();
    Sounds::getInstance().loadAllSounds();
    Game::GameEngine::getInstance().run(startInGame);
    return EXIT_SUCCESS;
}
