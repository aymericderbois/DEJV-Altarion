/* 
 * File:   InterfaceEngine.hh
 * Author: Aymeric
 *
 * Created on June 12, 2013, 10:40 PM
 */

#ifndef INTERFACEENGINE_HH
#define	INTERFACEENGINE_HH

#include "Elements/Frame.hh"
#include <iostream>

class InterfaceEngine
{
public:
    InterfaceEngine();
    virtual ~InterfaceEngine();
    
    void display(Graphic::GUI::Frame frame) {
        for(Component* c : frame.getComponents()) {
            std::cout << "draw" << std::endl;
            c->draw(this->__window);
        }
    }
private:
    sf::RenderWindow* __window;
public:
    void setWindow(sf::RenderWindow* window);
};

#endif	/* INTERFACEENGINE_HH */

