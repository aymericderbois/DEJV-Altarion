#ifndef BUTTON_HH
#define	BUTTON_HH

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Tools/Position.hh"
#include "Component.hh"

namespace Graphic
{
    namespace GUI
    {

        class Button : public Component
        {
        public:
            void init(int x, int y);
            virtual void draw(sf::RenderWindow* window);
            virtual void update(sf::RenderWindow* window);

            void setFont(std::string fontName);

        private:
            //sf::RectangleShape __shape;
            sf::Text __text;
            Tools::Position __position;
            Tools::Position __size;


            bool __isHover = false;
            sf::Font __font;

        public:
            void setPosition(Tools::Position __position);
            Tools::Position getPosition() const;
            void setText(std::string text);
            void setTextSize(int size);
        };
    }
}
#endif	/* BUTTON_HH */

