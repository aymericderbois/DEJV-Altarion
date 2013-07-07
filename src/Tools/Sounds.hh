#ifndef SOUNDS_HH
#define	SOUNDS_HH

#include <iostream>
#include <map>
#include <SFML/Audio.hpp>

class Sounds {
public:
    virtual ~Sounds();

    static Sounds& getInstance();
    void loadAllSounds();
    sf::SoundBuffer* get(std::string name);
private:
    Sounds();
    std::map<std::string, sf::SoundBuffer*>* __sounds;
};

#endif	/* SOUNDS_HH */

