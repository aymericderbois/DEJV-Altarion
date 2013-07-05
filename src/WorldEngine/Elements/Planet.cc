#include "Planet.hh"

Planet::Planet()
{
    
    //init buildings settings
    this->__max_mines       = rand() % 20 + 2;
    this->__max_refineries  = rand() % 20 + 2;
    this->__max_shipyards   = rand() % 10 + 1;
    
    this->__mines           = 0;
    this->__refineries      = 0;
    this->__shipyards       = 0;
    
    this->__fleet           = NULL;
}

Planet::~Planet()
{
    if (this->__fleet != NULL)
    {
        delete this->__fleet;
    }
}

Tools::Position Planet::GetPosition() const
{
    return __position;
}

void Planet::SetPosition(Tools::Position position)
{
    this->__position = position;
}

sf::Int32 Planet::GetSize() const
{
    return __size;
}

void Planet::SetSize(sf::Int32 size)
{
    this->__size = size;
}