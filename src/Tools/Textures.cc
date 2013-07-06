#include "Textures.hh"
#include <dirent.h>
#include <assert.h>

Textures::Textures() {
}

Textures::~Textures() {
}

Textures& Textures::getInstance() {
    static Textures instance;
    return instance;
}

void Textures::loadAllTextures() {
    this->__textures = new std::map<std::string, sf::Texture*>();
    std::string ressourceFolder = "ressources/images/";
    DIR* dir = NULL;
    struct dirent* currentFile = NULL;
    dir = opendir(ressourceFolder.c_str());
    assert(dir != NULL);
    
    while ((currentFile = readdir(dir)) != NULL) {
        std::string filename(currentFile->d_name);
        if (filename != "." && filename != "..") {
            unsigned found = filename.find_last_of(".");
            std::string filenameWithoutExt = filename.substr(0,found);
            sf::Texture* texture = new sf::Texture();
            texture->loadFromFile(ressourceFolder + filename);
            texture->setSmooth(true);
            assert(texture);
            this->__textures->insert(std::pair<std::string, sf::Texture*>(filenameWithoutExt, texture));
        }
    }
}

sf::Texture* Textures::get(std::string name) {
    assert(this->__textures->size() > 0);
    return this->__textures->at(name);
}