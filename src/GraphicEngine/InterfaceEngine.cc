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

void InterfaceEngine::setWindow(sf::RenderWindow* window) {
    this->__window = window;
}