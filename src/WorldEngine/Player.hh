#ifndef PLAYER_HH
#define	PLAYER_HH

class Player {
public:
    Player();
    virtual ~Player();
private:
    int __nbOre = 0; // Minerais
    int __nbGas = 0;
    int __nbPlanets = 0;
    int __nbShip = 0;
public:
    void setNbShip(int __nbShip);
    int getNbShip() const;
    void setNbPlanets(int __nbPlanets);
    int getNbPlanets() const;
    void setNbGas(int __nbGas);
    int getNbGas() const;
    void setNbOre(int __nbOre);
    int getNbOre() const;
};

#endif	/* PLAYER_HH */

