#include "Menu.hh"

namespace Interface
{
    Menu::Menu() {
    }

    Menu::~Menu() {
    }

    void Menu::init() {
        // @fixme : create menu interface here
    }

    void Menu::setExitButton(Graphic::Button __exitButton) {
        this->__exitButton = __exitButton;
    }

    Graphic::Button Menu::getExitButton() const {
        return __exitButton;
    }

    void Menu::setOptionsButton(Graphic::Button __optionsButton) {
        this->__optionsButton = __optionsButton;
    }

    Graphic::Button Menu::getOptionsButton() const {
        return __optionsButton;
    }

    void Menu::setStartButton(Graphic::Button __startButton) {
        this->__startButton = __startButton;
    }

    Graphic::Button Menu::getStartButton() const {
        return __startButton;
    }
}