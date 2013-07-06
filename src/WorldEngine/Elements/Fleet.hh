#ifndef FLEET_HH
#define FLEET_HH

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Ship.hh"
#include "../../Tools/Position.hh"

class Fleet {
public:
    Fleet();
    ~Fleet();
    void move();
    void setMoving(Tools::Position from, Tools::Position to);
private:
    std::list<Ship> __ships;
    Tools::Position* __departure;
    Tools::Position* __destination;
    Tools::Position* __current;

public:
    
    void addShip(Ship ship);
    std::list<Ship> getShips();
    
    Tools::Position* getCurrent() {
        return __current;
    }

    Tools::Position* getDestination() {
        return __destination;
    }

    Tools::Position* getDeparture() {
        return __departure;
    }
    
};

#endif /* FLEET_HH */