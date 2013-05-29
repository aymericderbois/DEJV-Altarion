#ifndef BUTTON_HH
#define	BUTTON_HH

#include <SFML/Graphics.hpp>

#include "../../Tools/Position.hh"

namespace Graphic
{
    class Button
    {
    public:
        void draw();
        void setFont(std::string fontName);

    private:
        Tools::Position __position;
        bool isHover = false;
        sf::Font __font;

    public:
        void setPosition(Tools::Position __position);
        Tools::Position getPosition() const;
    };
}
#endif	/* BUTTON_HH */

