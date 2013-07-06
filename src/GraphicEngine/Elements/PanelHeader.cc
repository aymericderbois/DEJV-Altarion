#include "PanelHeader.hh"
#include "../../Tools/Textures.hh"

namespace Graphic {
    namespace GUI {

        PanelHeader::PanelHeader() {
        }

        PanelHeader::~PanelHeader() {
        }

        void PanelHeader::draw(sf::RenderWindow* window) {
            //  draw planet icon
            if (this->__planetIcon != "") {
                sf::Texture* texture    = Textures::getInstance().get(this->getPlanetIcon());
                sf::Sprite  planetIcon;
                planetIcon.setTexture(*texture);
                planetIcon.setPosition(768, 60);
                planetIcon.setScale(0.7, 0.7);
            
                window->draw(planetIcon);
            }
            
            // draw planet name
            if (this->__planetName != "") {
                sf::Text text;
                sf::Font font;
                std::string fonturl = "ressources/fonts/biting.ttf";
            
                if (!font.loadFromFile(fonturl)) {
                    std::cerr << "Impossible de charger la font " << fonturl << std::endl;
                    exit(2);
                }
                text.setString(this->__planetName);
                text.setFont(font);
                text.setPosition(900, 70);

                window->draw(text);
            }
            
            for (Component* c : this->__components) {
                c->draw(window);
            }
        }

        void PanelHeader::update(sf::RenderWindow* window) {
            for (Component* c : this->__components) {
                c->update(window);
            }
        }
        
        void PanelHeader::setSize(Tools::Position __size) {
            this->__size.setX(__size.getX());
            this->__size.setY(__size.getY());
        }

        void PanelHeader::addComponent(Component* component) {
            this->__components.push_front(component);
        }
        
        std::list<Component*> PanelHeader::getComponents() const {
            return __components;
        }
        
        Tools::Position PanelHeader::getSize() const {
            return __size;
        }

        void PanelHeader::setPosition(Tools::Position __position) {
            this->__position.setX(__position.getX());
            this->__position.setY(__position.getY());
        }

        Tools::Position PanelHeader::getPosition() const {
            return __position;
        }

        void PanelHeader::setBackgroundColor(sf::Color __backgroundColor) {
            this->__backgroundColor = __backgroundColor;
        }

        sf::Color PanelHeader::getBackgroundColor() const {
            return __backgroundColor;
        }
        
        void PanelHeader::setOutlineColor(sf::Color __outlineColor) {
            this->__outlineColor = __outlineColor;
        }
        
        sf::Color PanelHeader::getOutlineColor() const {
            return __outlineColor;
        }
        
        void PanelHeader::setPlanetIcon(std::string __planetIcon)
        {
            this->__planetIcon = __planetIcon;
        }
        
        std::string PanelHeader::getPlanetIcon()
        {
            return this->__planetIcon;
        }
        
        void PanelHeader::setPlanetName(std::string __planetName)
        {
            this->__planetName = __planetName;
        }
        
        std::string PanelHeader::getPlanetName()
        {
            return this->__planetName;
        }
        
        void PanelHeader::setGas(Ressource* gas)
        {
            this->__gasRevenue = gas;
        }
        
        Ressource*   PanelHeader::getGas()
        {
            return this->__gasRevenue;
        }
        
        void PanelHeader::setMinerals(Ressource* minerals)
        {
            this->__mineralsRevenue = minerals;
        }
        
        Ressource*   PanelHeader::getMinerals()
        {
            return this->__mineralsRevenue;
        }
    }
}