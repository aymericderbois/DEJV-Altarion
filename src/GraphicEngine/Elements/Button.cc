#include <stdlib.h>
#include "Button.hh"

namespace Graphic {
    namespace GUI {

        Button::Button() {
        }

        Button::~Button() {
        }

        void Button::init(int x, int y) {
            this->setPosition(Tools::Position(x, y));
            this->setFont("biting.ttf");
            this->setTextSize(50);
            this->setText("");
        }

        void Button::draw(sf::RenderWindow* window) {
            if (this->__text.getString() == "") {
                window->draw(this->__text);
            } else {
                window->draw(this->__sprite);
            }
        }

        void Button::update(sf::RenderWindow* window) {
            sf::Vector2i pos = sf::Mouse::getPosition(*window);
            bool isXIn = pos.x > this->__position.getX() &&
                    pos.x < this->__position.getX() + this->__size.getX();
            bool isYIn = pos.y > this->__position.getY() &&
                    pos.y < this->__position.getY() + this->__size.getY();

            // @fixme Deplacer les traitements ci-dessous dans un event !
            if (isXIn && isYIn) {
                if (!this->__isHover) {

                    this->__isHover = true;
                    this->__event->onHover(this);
                }
            } else {
                if (this->__isHover) {
                    this->__isHover = false;
                    this->__event->onUnHover(this);
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->__isHover) {
                this->__event->onCLick(this);
            }
        }

        void Button::setFont(std::string fontName) {
            std::string font = "ressources/fonts/" + fontName;
            if (!this->__font.loadFromFile(font)) {
                std::cerr << "Impossible de charger la font " << font << std::endl;
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

        void Button::setEvent(EventListener* __event) {
            this->__event = __event;
        }

        EventListener* Button::getEvent() const {
            return __event;
        }

        void Button::setIsHover(bool __isHover) {
            this->__isHover = __isHover;
        }

        bool Button::isHover() const {
            return __isHover;
        }

        sf::Text& Button::getText() {
            return __text;
        }

        void Button::setId(std::string __id) {
            this->__id = __id;
        }

        std::string Button::getId() const {
            return __id;
        }
    }

}
