#ifndef FLEET_HH
#define FLEET_HH

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Ship.hh"

class Fleet
{
private:
    std::list<Ship> __ships;
    
public:
    void            addShip();
    std::list<Ship> getShips();
};

#endif /* FLEET_HH */
