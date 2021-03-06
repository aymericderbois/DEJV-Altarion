#include "Menu.hh"

namespace Interface {

    Menu::Menu() {
    }

    Menu::~Menu() {
    }

    void Menu::init() {
        // @fixme : create menu interface here
        this->setBackground("background.jpg");
        this->__startButton.init(20, 40);
        this->__startButton.setSize(Tools::Position(500, 60));
        this->__exitButton.init(20, 100);
        this->__exitButton.setSize(Tools::Position(500, 60));



        this->__startButton.setId("START");
        this->__exitButton.setId("EXIT");

        this->__startButton.setText("Launch Game");
        this->__exitButton.setText("Exit game");

        this->addComponent(&this->__startButton);
        this->addComponent(&this->__exitButton);

        this->__exitButton.setEvent(&this->__action);
        this->__startButton.setEvent(&this->__action);

    }

    void Menu::buttonOnHover(Graphic::GUI::Button* button) {
        button->setTextSize(40);
    }

    void Menu::setExitButton(Graphic::GUI::Button __exitButton) {
        this->__exitButton = __exitButton;
    }

    Graphic::GUI::Button Menu::getExitButton() const {
        return __exitButton;
    }

    void Menu::setOptionsButton(Graphic::GUI::Button __optionsButton) {
        this->__optionsButton = __optionsButton;
    }

    Graphic::GUI::Button Menu::getOptionsButton() const {
        return __optionsButton;
    }

    void Menu::setStartButton(Graphic::GUI::Button __startButton) {
        this->__startButton = __startButton;
    }

    Graphic::GUI::Button Menu::getStartButton() const {
        return __startButton;
    }
}