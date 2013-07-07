#ifndef FLEET_HH
#define FLEET_HH

#include <iostream>
#include <stdlib.h>
#include <list>
#include "Ship.hh"
#include "../../Tools/Position.hh"

class Planet;

class Fleet {
public:
    Fleet();
    ~Fleet();
    void move();
    void setMoving(Planet* planetDestination, Tools::Position from, Tools::Position to);
    void moveEnded();
private:
    std::list<Ship> __ships;
    Tools::Position* __destination;
    Tools::Position* __current;
    Planet* __planetDestination;
public:
    
    void addShip(Ship ship);
    std::list<Ship> getShips();
    
    Tools::Position* getCurrent() {
        return __current;
    }

    Tools::Position* getDestination() {
        return __destination;
    }

    void setPlanetDestination(Planet* __planet);
    Planet* getPlanetDestination();
    
};

#endif /* FLEET_HH */