#include "Position.hh"

Position::Position() {
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::~Position() {
}

void Position::SetY(int y) {
    this->y = y;
}

int Position::GetY() const {
    return y;
}

void Position::SetX(int x) {
    this->x = x;
}

int Position::GetX() const {
    return x;
}

