#include "GameInformation.hh"
#include "GameEngine.hh"

namespace Game
{

    GameInformation::GameInformation() {
        this->currentPage = Game::Pages::MENU;
    }

    GameInformation::~GameInformation() {
    }

    bool GameInformation::isInMenu() {
        return this->currentPage == Pages::MENU;
    }
    
    bool GameInformation::isInGame() {
        return this->currentPage == Pages::IN_GAME;
    }

    void GameInformation::setCurrentPage(int currentPage) {
        this->currentPage = currentPage;
    }

    int GameInformation::getCurrentPage() const {
        return currentPage;
    }
}