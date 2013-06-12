#ifndef COMPONENT_HH
#define	COMPONENT_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void draw(sf::RenderWindow* window) = 0;
private:

};

#endif	/* COMPONENT_HH */

