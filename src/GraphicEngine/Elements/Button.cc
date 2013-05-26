#include "Button.hh"

void Graphic::Button::setPosition(Position __position) {
    this->__position = __position;
}

Position Graphic::Button::getPosition() const {
    return __position;
}