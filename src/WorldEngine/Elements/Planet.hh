#ifndef PLANET_HH
#define	PLANET_HH

#include <sstream>

#include <SFML/System.hpp>
#include "../../Tools/Position.hh"

#include "../../GraphicEngine/Elements/Button.hh"

#include "Fleet.hh"

class Planet : public Graphic::GUI::Button
{
public:
    Planet();
    virtual ~Planet();
    
private:
    // Gameplay
    int             __mines;
    int             __refineries;
    int             __shipyards;
    
    int             __max_mines;
    int             __max_refineries;
    int             __max_shipyards;
    
    Fleet*          __fleet; // might be changed into a list in the future
    
    // Display
    std::string     __name;
    sf::Int32       __size;
    Tools::Position __position;
    
public:
    std::string     getName();
    void            setName(std::string name);
    
    Tools::Position GetPosition() const;
    void            SetPosition(Tools::Position position);
    
    sf::Int32       GetSize() const;
    void            SetSize(sf::Int32 size);
};

#endif	/* PLANET_HH */

