#include "Position.hh"

namespace Tools
{
    Position::Position() {
    }

    Position::Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Position::~Position() {
    }

    void Position::setY(int y) {
        this->y = y;
    }

    int Position::getY() const {
        return y;
    }

    void Position::setX(int x) {
        this->x = x;
    }

    int Position::getX() const {
        return x;
    }
}