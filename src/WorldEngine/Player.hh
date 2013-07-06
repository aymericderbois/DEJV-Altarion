#ifndef PLAYER_HH
#define	PLAYER_HH

#include "Elements/ElementsConfig.hh"

class Player {
public:
    Player();
    virtual ~Player();
private:
    float __nbOre = BASE_STOCK_MINERALS; // Minerais
    float __nbGas = BASE_STOCK_GAS;
    int __nbPlanets = 0;
    int __nbShip = 0;
    int __id;
public:
    void setNbShip(int __nbShip);
    int getNbShip() const;
    
    void setNbPlanets(int __nbPlanets);
    int getNbPlanets() const;
    
    void setNbGas(float __nbGas);
    float getNbGas() const;
    
    void setNbOre(float __nbOre);
    float getNbOre() const;
    
    void setId(int __id);
    int getId() const;
};

#endif	/* PLAYER_HH */

