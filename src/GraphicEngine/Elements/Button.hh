#ifndef BUTTON_HH
#define	BUTTON_HH

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Tools/Position.hh"

namespace Graphic
{
    class Button
    {
    public:
        void init(int x, int y);
        void draw();
        void setFont(std::string fontName);

    private:
        sf::RectangleShape* __shape;
        Tools::Position __position;
        //bool isHover = false;
        sf::Font __font;

    public:
        void setShape(sf::RectangleShape *shape);
        sf::RectangleShape* getShape();
        
        void setPosition(Tools::Position __position);
        Tools::Position getPosition() const;
    };
}
#endif	/* BUTTON_HH */

