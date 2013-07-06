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
    std::string     __textureName;
    
public:
    std::string     getName();
    void            setName(std::string name);
    
    std::string     getTextureName();
    void            setTextureName(std::string texturename);
};

std::string     chooseTexture();

#endif	/* PLANET_HH */

