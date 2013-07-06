#ifndef BUTTON_HH
#define	BUTTON_HH

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Tools/Position.hh"
#include "../../libs/Event/EventListener.hh"
#include "../../libs/Event/EventLauncher.hh"

#include "Component.hh"

namespace Graphic {
    namespace GUI {

        class Button : public Component, public EventLauncher {
        public:
            Button();
            virtual ~Button();
            void init(int x, int y);
            virtual void draw(sf::RenderWindow* window);
            virtual void update(sf::RenderWindow* window);
            void setTexture(std::string);
            void setFont(std::string fontName);
            void setSpriteRatio(float ratio);
        private:
            // For text button
            sf::Text __text;
            sf::Font __font;
            std::string __id;

            // For image button
            sf::Sprite __sprite;
            
            Tools::Position __position;
            Tools::Position __size;
            bool __isHover = false;
            
            EventListener *__event;

        public:
            void setPosition(Tools::Position __position);
            Tools::Position getPosition() const;
            void setText(std::string text);
            void setTextSize(int size);
            void setEvent(EventListener* __event);
            EventListener* getEvent() const;
            void setIsHover(bool __isHover);
            bool isHover() const;
            sf::Text& getText();
            void setId(std::string __id);
            std::string getId() const;
            void setSize(Tools::Position __size);
            Tools::Position getSize() const;
        };
    }
}
#endif	/* BUTTON_HH */
