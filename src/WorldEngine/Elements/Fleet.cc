#include "Fleet.hh"

Fleet::Fleet() {

}

Fleet::~Fleet() {

}

void Fleet::move() {

}

void Fleet::setMoving(Tools::Position from, Tools::Position to) {
    this->__departure = new Tools::Position(from.getX(), from.getY());
    this->__current = new Tools::Position(from.getX(), from.getY());
    this->__destination = new Tools::Position(to.getX(), to.getY());
}

void Fleet::addShip(Ship ship) {
    this->__ships.push_front(ship);
}

std::list<Ship> Fleet::getShips() {
    return this->__ships;
}

