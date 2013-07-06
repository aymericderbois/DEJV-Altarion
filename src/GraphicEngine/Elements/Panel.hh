#ifndef PANEL_HH
#define	PANEL_HH

#include "Component.hh"
#include "../../Tools/Position.hh"
#include <list>

namespace Graphic {
    namespace GUI {
        class Panel : public Component{
        public:
            Panel();
            void draw(sf::RenderWindow* window);
            void update(sf::RenderWindow* window);
            void addComponent(Component* component);
            virtual ~Panel();
        protected:
            Tools::Position __position;
            Tools::Position __size;
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
        };
    }
}
#endif	/* PANEL_HH */

