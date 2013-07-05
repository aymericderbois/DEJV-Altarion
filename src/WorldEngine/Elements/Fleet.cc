#include "Fleet.hh"

Fleet::Fleet()
{
    
}

Fleet::~Fleet()
{
    
}

void            Fleet::addShip(Ship ship)
{
    this->__ships.push_front(ship);
}

std::list<Ship> Fleet::getShips()
{
    return this->__ships;
}

