#ifndef FLEET_HH
#define FLEET_HH

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Ship.hh"

class Fleet
{
public:
    Fleet();
    ~Fleet();
private:
    std::list<Ship> __ships;
    
public:
    void            addShip(Ship ship);
    std::list<Ship> getShips();
};

#endif /* FLEET_HH */
