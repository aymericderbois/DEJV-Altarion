/* 
 * File:   Textures.cpp
 * Author: Aymeric
 * 
 * Created on 4 juillet 2013, 16:01
 */

#include "Textures.hh"

Textures::Textures() {
}

Textures::~Textures() {
}

Textures Textures::getInstance() {
    static Textures instance;
    return instance;
}

void Textures::loadAllTextures() {
    /* @fixme*/
}