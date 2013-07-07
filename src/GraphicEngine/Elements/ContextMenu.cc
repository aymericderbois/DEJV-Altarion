#include "ContextMenu.hh"

namespace Graphic {
    namespace GUI {

        ContextMenu::ContextMenu() {
        }

        ContextMenu::~ContextMenu() {
        }

        void ContextMenu::draw(sf::RenderWindow* window) {
            sf::RectangleShape rectangle(sf::Vector2f(
                this->__size.getX(), this->__size.getY()
            ));
            
            rectangle.setPosition(this->__position.getX(), this->__position.getY());
            rectangle.setFillColor(this->__backgroundColor);
            rectangle.setOutlineThickness(2.f);
            rectangle.setOutlineColor(this->__outlineColor);
            
            window->draw(rectangle);
            for (Component* c : this->__components) {
                c->draw(window);
            }
        }

        void ContextMenu::update(sf::RenderWindow* window) {
            for (Component* c : this->__components) {
                c->update(window);
            }
        }
        
        void ContextMenu::addComponent(Component* component) {
            this->__components.push_front(component);
        }
        
        std::list<Component*> ContextMenu::getComponents() const {
            return __components;
        }

        void ContextMenu::setSize(Tools::Position __size) {
            this->__size.setX(__size.getX());
            this->__size.setY(__size.getY());
        }

        Tools::Position ContextMenu::getSize() const {
            return __size;
        }

        void ContextMenu::setPosition(Tools::Position __position) {
            this->__position.setX(__position.getX());
            this->__position.setY(__position.getY());
        }

        Tools::Position ContextMenu::getPosition() const {
            return __position;
        }

        void ContextMenu::setBackgroundColor(sf::Color __backgroundColor) {
            this->__backgroundColor = __backgroundColor;
        }

        sf::Color ContextMenu::getBackgroundColor() const {
            return __backgroundColor;
        }
        
        void ContextMenu::setOutlineColor(sf::Color __outlineColor) {
            this->__outlineColor = __outlineColor;
        }
        
        sf::Color ContextMenu::getOutlineColor() const {
            return __outlineColor;
        }
        
        void ContextMenu::setPanelHeader (PanelHeader* __header)
        {
            this->__header = __header;
        }
        
        PanelHeader* ContextMenu::getPanelHeader()
        {
            return this->__header;
        }
        
        void ContextMenu::setMineBtn (Button *btn)
        {
            this->__mineBtn = btn;
        }
        
        Button* ContextMenu::getMineBtn()
        {
            return this->__mineBtn;
        }
        
        void ContextMenu::setRefineryBtn (Button *btn)
        {
            this->__refineryBtn = btn;
        }
        
        Button* ContextMenu::getRefineryBtn()
        {
            return this->__refineryBtn;
        }
        
        void ContextMenu::setShipyardBtn (Button *btn)
        {
            this->__shipyardBtn = btn;
        }
        
        Button* ContextMenu::getShipyardBtn()
        {
            return this->__shipyardBtn;
        }
        
        
        void ContextMenu::setMineLabel (Label *btn)
        {
            this->__mineLabel = btn;
        }
        
        Label* ContextMenu::getMineLabel()
        {
            return this->__mineLabel;
        }
        
        void ContextMenu::setRefineryLabel (Label *btn)
        {
            this->__refineryLabel = btn;
        }
        
        Label* ContextMenu::getRefineryLabel()
        {
            return this->__refineryLabel;
        }
        
        void ContextMenu::setShipyardLabel (Label *btn)
        {
            this->__shipyardLabel = btn;
        }
        
        Label* ContextMenu::getShipyardLabel()
        {
            return this->__shipyardLabel;
        }
        
    }
}