#ifndef PLANET_HH
#define	PLANET_HH

#include <sstream>

#include <SFML/System.hpp>
#include "../../Tools/Position.hh"

#include "../../GraphicEngine/Elements/Button.hh"

#include "Fleet.hh"
#include "../Player.hh"
#include "ElementsConfig.hh"

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
    
    Player*         __owner;
    // Display
    std::string     __name;
    std::string     __textureName;
    
    std::string     __backgroundName;
    
public:
    std::string     getName();
    void            setName(std::string name);
    
    std::string     getTextureName();
    void            setTextureName(std::string texturename);
    
    int             getGasRevenue();
    void            setGasRevenue(int gas);
    
    int             getMineralsRevenue();
    void            setMineralsRevenue(int minerals);
    
    Player*         getOwner();
    void            setOwner(Player* owner);
    
    Fleet*          getFleet();
    void            setFleet(Fleet* fleet);
    
    int             getMines() { return this->__mines; }
    void            setMines(int mines) { this->__mines = mines; }
    
    int             getRefineries() { return this->__refineries; }
    void            setRefineries(int refineries)  { this->__refineries = refineries; }

    int             getShipyards() { return this->__shipyards; }
    void            setShipyards(int shipyards) { this->__shipyards = shipyards; }

    int             getMaxMines() { return this->__max_mines; }
    void            setMaxMines(int maxMines) { this->__max_mines = maxMines; }

    int             getMaxRefineries() { return this->__max_refineries; }
    void            setMaxRefineries(int maxRefineries) { this->__max_refineries = maxRefineries; }
    
    int             getMaxShipyards() { return this->__max_shipyards; }
    void            setMaxShipyards(int maxShipyards) { this->__max_shipyards = maxShipyards; }
};

std::string     chooseTexture();

#endif	/* PLANET_HH */

