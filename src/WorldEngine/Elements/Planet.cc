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
    
    std::stringstream name;
    name << "P";
    name << rand() % 9 + 0;
    name << "X";
    name << rand() % 999 + 0;
    
    this->setName(name.str());
}

Planet::~Planet()
{
    if (this->__fleet != NULL)
    {
        delete this->__fleet;
    }
}


std::string     Planet::getName()
{
    return this->__name;
}

void            Planet::setName(std::string name)
{
    this->__name = name;
}

Tools::Position Planet::GetPosition() const
{
    return __position;
}

void            Planet::SetPosition(Tools::Position position)
{
    this->__position = position;
}

sf::Int32       Planet::GetSize() const
{
    return __size;
}

void            Planet::SetSize(sf::Int32 size)
{
    this->__size = size;
}