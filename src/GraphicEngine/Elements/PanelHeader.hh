#ifndef PANEL_HEADER_HH
#define	PANEL_HEADER_HH

#include "Component.hh"
#include "../../Tools/Position.hh"
#include <list>

namespace Graphic {
    namespace GUI {
        class PanelHeader : public Component{
        public:
            PanelHeader();
            void draw(sf::RenderWindow* window);
            void update(sf::RenderWindow* window);
            virtual ~PanelHeader();

        private:
            Tools::Position __position;
            Tools::Position __size;
            
            std::string __planetIcon;
            std::string __planetName;
            
            sf::Color __backgroundColor;
            sf::Color __outlineColor;
            std::list<Component*> __components;
            
        public:
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
        };
    }
}
#endif	/* PANEL_HEADER_HH */

