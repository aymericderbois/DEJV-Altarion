#ifndef PANEL_HEADER_HH
#define	PANEL_HEADER_HH

#include "Component.hh"
#include "Ressource.hh"
#include "../../Tools/Position.hh"
#include <list>

namespace Graphic {
    namespace GUI {
        class PanelHeader : public Component{
        public:
            PanelHeader();
            void draw(sf::RenderWindow*     window);
            void update(sf::RenderWindow*   window);
            void addComponent(Component*    component);
            virtual ~PanelHeader();

        private:
            Tools::Position __position;
            Tools::Position __size;
            
            std::string __planetIcon;
            std::string __planetName;
            
            Ressource   *__gasRevenue;
            Ressource   *__mineralsRevenue;
            
            sf::Color __backgroundColor;
            sf::Color __outlineColor;
            std::list<Component*> __components;
            
        public:
            std::list<Component*> getComponents() const;
            
            void setSize(Tools::Position __size);
            Tools::Position getSize() const;
            
            void setPosition(Tools::Position __position);
            Tools::Position getPosition() const;
            
            void setBackgroundColor(sf::Color __backgroundColor);
            sf::Color getBackgroundColor() const;
            
            void setOutlineColor(sf::Color __outlineColor);
            sf::Color getOutlineColor() const;
            
            void setPlanetIcon(std::string __planetIcon);
            std::string getPlanetIcon();
            
            void setPlanetName(std::string __planetName);
            std::string getPlanetName();
            
            void setGas(Ressource* gas);
            Ressource*   getGas();
            
            void setMinerals(Ressource* minerals);
            Ressource*   getMinerals();
            
        };
    }
}
#endif	/* PANEL_HEADER_HH */

