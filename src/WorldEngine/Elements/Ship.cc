#include "Ship.hh"

Ship::Ship()
{
}

Ship::~Ship()
{
}

void    Ship::setArmor(int      armor)
{
    this->__armor = armor;
}

void    Ship::setShield(int     shield)
{
    this->__shield = shield;
}

void    Ship::setStrength(int   strength)
{
    this->__strength = strength;
}

int     Ship::getArmor()
{
    return this->__armor;
}

int     Ship::getShield()
{
    return this->__shield;
}

int     Ship::getStrength()
{
    return this->__strength;
}