#ifndef PLANET_HH
#define	PLANET_HH

#include <SFML/System.hpp>
#include "../../Tools/Position.hh"

class Planet {
public:
    Planet();
    virtual ~Planet();
private:
    sf::Int32 __size;
    Tools::Position __position;
public:
    Tools::Position GetPosition() const;
    void SetPosition(Tools::Position position);
    sf::Int32 GetSize() const;
    void SetSize(sf::Int32 size);
};

#endif	/* PLANET_HH */

