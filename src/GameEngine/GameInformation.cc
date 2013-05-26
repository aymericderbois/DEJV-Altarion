#include "GameInformation.hh"
#include "GameEngine.hh"

Game::GameInformation::GameInformation() {
    this->currentPage = Game::Pages::MENU;
}

Game::GameInformation::~GameInformation() {
}

void Game::GameInformation::SetCurrentPage(int currentPage) {
    this->currentPage = currentPage;
}

int Game::GameInformation::GetCurrentPage() const {
    return currentPage;
}