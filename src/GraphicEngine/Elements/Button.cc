#include "Button.hh"

namespace Graphic
{

    void Button::init(int x, int y) {
        
        this->setPosition(Tools::Position (x, y));
        this->__shape->setPosition(this->getPosition().getX(), this->getPosition().getY());
        
        this->__shape->setSize(sf::Vector2f(50, 30));
        
        this->__shape->setFillColor(sf::Color::Yellow);
        this->__shape->setOutlineColor(sf::Color::Blue);
        this->__shape->setOutlineThickness(3);
    }
    

    void Button::setFont(std::string fontName) {
        if (!this->__font.loadFromFile(fontName)) {
            // erreur...
        }
    }

    void Button::setShape(sf::RectangleShape *shape) {
        this->__shape = shape;
    }
    
    sf::RectangleShape* Button::getShape() {
        return this->__shape;
    }
    
    void Button::setPosition(Tools::Position __position) {
        this->__position = __position;
    }

    Tools::Position Button::getPosition() const {
        return __position;
    }
}
