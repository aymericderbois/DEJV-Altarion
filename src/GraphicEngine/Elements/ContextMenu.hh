#ifndef CONTEXT_MENU_HH
#define	CONTEXT_MENU_HH

#include "Component.hh"
#include "PanelHeader.hh"
#include "Button.hh"
#include "label.hh"
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
            
            
            // to be moved in view class
            PanelHeader *__header;
            Button      *__mineBtn;
            Button      *__refineryBtn;
            Button      *__shipyardBtn;
            
            Label       *__mineLabel;
            Label       *__refineryLabel;
            Label       *__shipyardLabel;
            
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
            
            void setPanelHeader (PanelHeader *__header);
            PanelHeader* getPanelHeader();
            
            void setMineBtn (Button *btn);
            Button* getMineBtn();
            
            void setRefineryBtn (Button *btn);
            Button* getRefineryBtn();
            
            void setShipyardBtn (Button *btn);
            Button* getShipyardBtn();
            
            
            void setMineLabel (Label *btn);
            Label* getMineLabel();
            
            void setRefineryLabel (Label *btn);
            Label* getRefineryLabel();
            
            void setShipyardLabel (Label *btn);
            Label* getShipyardLabel();
        };
    }
}
#endif	/* CONTEXT_MENU_HH */

