#ifndef TEXTURES_HH
#define	TEXTURES_HH

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class Textures {
public:
    virtual ~Textures();
    Textures getInstance();
    void loadAllTextures();
private:
    Textures();
    std::map<std::string, sf::Texture*> __textures;
};

#endif	/* TEXTURES_HH */

