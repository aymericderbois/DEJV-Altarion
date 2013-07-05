#ifndef TEXTURES_HH
#define	TEXTURES_HH

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class Textures {
public:
    virtual ~Textures();
    static Textures getInstance();
    void loadAllTextures();
    sf::Texture* get(std::string name);
private:
    Textures();
    std::map<std::string, sf::Texture*> __textures;
};

#endif	/* TEXTURES_HH */

