#include "Planet.hh"

Planet::Planet() {
}

Planet::~Planet() {
}

Tools::Position Planet::GetPosition() const {
    return __position;
}

void Planet::SetPosition(Tools::Position position) {
    this->__position = position;
}

sf::Int32 Planet::GetSize() const {
    return __size;
}

void Planet::SetSize(sf::Int32 size) {
    this->__size = size;
}