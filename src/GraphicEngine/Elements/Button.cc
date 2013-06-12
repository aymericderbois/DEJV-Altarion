#include <stdlib.h>

#include "Button.hh"

namespace Graphic
{
    namespace GUI
    {

        void Button::init(int x, int y) {
            this->setPosition(Tools::Position(x, y));
            this->setFont("biting.ttf");
            this->setTextSize(50);
            this->setText("A Button");
        }

        void Button::draw(sf::RenderWindow* window) {
            window->draw(this->__text);
        }

        void Button::setFont(std::string fontName) {
            std::string font = "ressources/fonts/" + fontName;
            if (!this->__font.loadFromFile(font)) {
                std::cout << "Impossible de charger la font " << font << std::endl;
                exit(2);
            }
            this->__text.setFont(this->__font);
        }

        void Button::setPosition(Tools::Position position) {
            this->__position = position;
            this->__text.setPosition(position.getX(), position.getY());
        }

        Tools::Position Button::getPosition() const {
            return __position;
        }

        void Button::setText(std::string text) {
            this->__text.setString(text);
        }

        void Button::setTextSize(int size) {
            this->__text.setCharacterSize(size);
        }
    }

}
