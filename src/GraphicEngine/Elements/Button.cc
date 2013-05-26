#include "Button.hh"

void Button::setPosition(Position __position) {
    this->__position = __position;
}

Position Button::getPosition() const {
    return __position;
}