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

        void Button::update(sf::RenderWindow* window) {
            sf::Vector2i pos = sf::Mouse::getPosition(*window);
            bool isXIn = pos.x > this->__position.getX() &&
                    pos.x < this->__position.getX() + this->__size.getX();
            bool isYIn = pos.y > this->__position.getY() &&
                    pos.y < this->__position.getY() + this->__size.getY();
            if (isXIn && isYIn) {
                this->__isHover = true;
                this->__text.setColor(sf::Color::Red);
            } else {
                this->__isHover = false;
                this->__text.setColor(sf::Color::White);
            }
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
            this->__size.setX(80);
            this->__size.setY(40);

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
