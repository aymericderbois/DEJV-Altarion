#include "Ressource.hh"

#include "../../Tools/Textures.hh"

namespace Graphic {
    namespace GUI {
        
Ressource::Ressource() {
}

Ressource::~Ressource() {
}

void Ressource::draw(sf::RenderWindow* window)
{
    //  draw planet icon
    if (this->__icon != "") {
        sf::Texture* texture    = Textures::getInstance().get(this->__icon);
        sf::Sprite  planetIcon;
        planetIcon.setTexture(*texture);
        planetIcon.setPosition(this->getPosition().getX(), this->getPosition().getY());
        planetIcon.setScale(0.5, 0.5);
        
        window->draw(planetIcon);
    }
    
    // draw planet name
    if (this->__value != "") {
        sf::Text text;
        sf::Font font;
        std::string fonturl = "ressources/fonts/biting.ttf";
        
        if (!font.loadFromFile(fonturl)) {
            std::cerr << "Impossible de charger la font " << fonturl << std::endl;
            exit(2);
        }
        text.setString(this->__value);
        text.setFont(font);
        text.setPosition(this->getPosition().getX() + 40, this->getPosition().getY());
        
        window->draw(text);
    }
}

void Ressource::update(sf::RenderWindow* window)
{
    
}

void            Ressource::setValue(std::string text)
{
    this->__value = text;
}

std::string        Ressource::getValue()
{
    return this->__value;
}

void Ressource::setPosition(Tools::Position position) {
    this->__position = position;
}

void Ressource::setIcon(std::string name) {
    this->__icon = name;
}

Tools::Position Ressource::getPosition() const {
    return __position;
}

void Ressource::setSize(Tools::Position __size) {
    this->__size = __size;
}

Tools::Position Ressource::getSize() const {
    return __size;
}
    }
}