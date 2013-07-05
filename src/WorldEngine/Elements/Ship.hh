//
//  Ship.h
//  UniversalSupremacy
//
//  Created by Quentin on 7/5/13.
//
//

#ifndef __SHIP_HH
#define __SHIP_HH

#include <iostream>

class Ship
{
public:
    Ship();
    ~Ship();
    
private:
    int     __armor;
    int     __shield;
    int     __strength;
    
public:
    void    setArmor(int    armor);
    void    setShield(int   shield);
    void    setStrength(int strength);
    
    int     getArmor();
    int     getShield();
    int     getStrength();
};

#endif /* __SHIP_HH */
