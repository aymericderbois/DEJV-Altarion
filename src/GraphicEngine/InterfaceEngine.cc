/* 
 * File:   InterfaceEngine.cc
 * Author: Aymeric
 * 
 * Created on June 12, 2013, 10:40 PM
 */

#include "InterfaceEngine.hh"

InterfaceEngine::InterfaceEngine() {
}

InterfaceEngine::~InterfaceEngine() {
}

void InterfaceEngine::update(Graphic::GUI::Frame& frame) {
    frame.update();
    for (Component* c : frame.getComponents()) {
        c->update(this->__window);
    }
}

void InterfaceEngine::display(Graphic::GUI::Frame& frame) {
    frame.draw(this->__window);
}

void InterfaceEngine::setWindow(sf::RenderWindow* window) {
    this->__window = window;
}