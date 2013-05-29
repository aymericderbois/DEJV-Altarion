#include "Button.hh"

namespace Graphic
{

    void Button::draw() {
    }

    void Button::setFont(std::string fontName) {
        if (!this->__font.loadFromFile(fontName)) {
            // erreur...
        }
    }

    void Button::setPosition(Tools::Position __position) {
        this->__position = __position;
    }

    Tools::Position Button::getPosition() const {
        return __position;
    }
}
