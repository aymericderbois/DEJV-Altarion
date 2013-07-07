/* 
 * File:   MenuAction.cc
 * Author: Aymeric
 * 
 * Created on 2 juillet 2013, 14:29
 */

#include "MenuAction.hh"
#include "../GameEngine/GameEngine.hh"

MenuAction::MenuAction() {
}

MenuAction::~MenuAction() {
}

void MenuAction::onCLick(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    if (button->getId() == "EXIT") exit(2);
    
    if (button->getId() == "START") {
        Game::GameEngine::getInstance().getGameInformation()->setCurrentPage(Game::IN_GAME);
        std::cout << Game::GameEngine::getInstance().getGameInformation()->getCurrentPage() << std::endl;
    }
}

void MenuAction::onHover(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    button->getText().setColor(sf::Color::Red);
    button->getText().rotate(-5.0);
}

void MenuAction::onUnHover(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    button->getText().setColor(sf::Color::White);
    button->getText().rotate(5.0);
}