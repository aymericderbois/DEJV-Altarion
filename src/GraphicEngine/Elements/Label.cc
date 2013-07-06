#include "Label.hh"

namespace Graphic {
    namespace GUI {

        Label::Label() {
        }

        Label::~Label() {
        }

        void Label::init(int x, int y) {
            this->setPosition(Tools::Position(x, y));
            this->setFont("biting.ttf");
            this->setTextSize(10);
            this->setText("");
        }

        void Label::draw(sf::RenderWindow* window) {
            window->draw(this->__text);
        }

        void Label::update(sf::RenderWindow* window) {
            /* Nothing for the moment ? */
        }

        void Label::setText(std::string __text) {
            this->__text.setString(__text);
        }

        void Label::setFont(std::string fontName) {
            std::string font = "ressources/fonts/" + fontName;
            if (!this->__font.loadFromFile(font)) {
                std::cerr << "Impossible de charger la font " << font << std::endl;
                exit(2);
            }
            this->__text.setFont(this->__font);
        }

        void Label::setPosition(Tools::Position __position) {
            this->__text.setPosition(__position.getX(), __position.getY());
        }

        void Label::setTextSize(int size) {
            this->__text.setCharacterSize(size);
        }
    }
}
