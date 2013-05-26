#include "TextButton.hh"

void TextButton::draw() {

}

std::string TextButton::getText() const {
    return this->__text;
}

void TextButton::setText(const std::string &text) {
    this->__text = text;
}
