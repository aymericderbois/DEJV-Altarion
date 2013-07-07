#ifndef MUSICS_HH
#define	MUSICS_HH

#include <iostream>
#include <map>
#include <SFML/Audio.hpp>

class Musics {
public:
    virtual ~Musics();

    static Musics& getInstance();
    void loadAllMusics();
    sf::Music* get(std::string name);
private:
    Musics();
    std::map<std::string, sf::Music*>* __musics;
};

#endif	/* MUSICS_HH */

