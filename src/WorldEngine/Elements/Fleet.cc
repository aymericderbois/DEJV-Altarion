#include "Fleet.hh"

Fleet::Fleet() {

}

void Fleet::setPlanetDestination(Planet* __planet) {
    this->__planetDestination = __planet;
}

Planet* Fleet::getPlanetDestination() {
    return __planetDestination;
}

Fleet::~Fleet() {

}

void Fleet::move() {

}
void Fleet::moveEnded() {
    delete this->__current;
    delete this->__destination;
    this->__planetDestination = nullptr;
}

void Fleet::setMoving(Planet* planetDestination, Tools::Position from, Tools::Position to) {
    this->__current = new Tools::Position(from.getX(), from.getY());
    this->__destination = new Tools::Position(to.getX(), to.getY());
    this->__planetDestination = planetDestination;
}

void Fleet::addShip(Ship ship) {
    this->__ships.push_front(ship);
}

std::list<Ship> Fleet::getShips() {
    return this->__ships;
}

