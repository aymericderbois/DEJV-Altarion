#ifndef CONTEXT_MENU_HH
#define	CONTEXT_MENU_HH

#include "Component.hh"
#include "PanelHeader.hh"
#include "Button.hh"
#include "Label.hh"
#include "../../Tools/Position.hh"
#include <list>

namespace Graphic {
    namespace GUI {
        class ContextMenu : public Component{
        public:
            ContextMenu();
            void draw(sf::RenderWindow* window);
            void update(sf::RenderWindow* window);
            void addComponent(Component* component);
            virtual ~ContextMenu();
        private:
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
#endif	/* CONTEXT_MENU_HH */

