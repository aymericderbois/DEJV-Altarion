#include <stdlib.h>
#include "Button.hh"
#include "../../Tools/Textures.hh"
#include "../../Tools/Sounds.hh"

namespace Graphic {
    namespace GUI {

        Button::Button() {
            this->setSound("button");
            this->setSoundError("error");
        }

        Button::~Button() {
        }

        void Button::init(int x, int y) {
            this->setPosition(Tools::Position(x, y));
            this->setFont("biting.ttf");
            this->setTextSize(50);
            this->setText("");
            this->setBackground("");
        }

        void Button::draw(sf::RenderWindow* window) {
            if (this->__backgroundName != "")
            {
                window->draw(this->__background);
            }
            
            if (this->__text.getString() != "") {
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
            
            bool isButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left)
                ||sf::Mouse::isButtonPressed(sf::Mouse::Right);
            if (isButtonPressed && this->__isHover && (this->__active == 0)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    this->__event->onCLick(this, sf::Mouse::Left);
                else
                    this->__event->onCLick(this, sf::Mouse::Right);
                this->__active = 10;
            }
            else
            {
                if (this->__active > 0)
                    this->__active--;
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
            this->__sprite.setPosition(position.getX(), position.getY());
            this->__background.setPosition(position.getX() - 5, position.getY() - 5);
        }

        void Button::setTexture(std::string name) {
            sf::Texture* texture = Textures::getInstance().get(name);
            this->__sprite.setTexture(*texture);
        }
        
        void Button::setSpriteRatio(float ratio) {
            this->__sprite.scale(sf::Vector2f(ratio, ratio));
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

        void Button::setSize(Tools::Position __size) {
            this->__size = __size;
        }

        Tools::Position Button::getSize() const {
            return __size;
        }
        
        void Button::setBackground(std::string bgname)
        {
            this->__backgroundName = bgname;
            sf::Texture* texture = Textures::getInstance().get(this->__backgroundName);
            this->__background.setTexture(*texture);
            this->__background.setScale(0.5, 0.5);
        }
        
        void Button::setSound(std::string sound) {
            sf::SoundBuffer* buffer = Sounds::getInstance().get(sound);
            this->__sound.setBuffer(*buffer);
        }
        
        void Button::fireSound()
        {
            this->__sound.stop();
            this->__sound.play();
        }
        
        void Button::setSoundError(std::string sound) {
            sf::SoundBuffer* buffer = Sounds::getInstance().get(sound);
            this->__soundError.setBuffer(*buffer);
        }
        
        void Button::fireSoundError()
        {
            this->__soundError.stop();
            this->__soundError.play();
        }
    }

}
