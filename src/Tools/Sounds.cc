#include "Sounds.hh"
#include <dirent.h>
#include <assert.h>

Sounds::Sounds() {
}

Sounds::~Sounds() {
}

Sounds& Sounds::getInstance() {
    static Sounds instance;
    return instance;
}

void Sounds::loadAllSounds() {
    this->__sounds = new std::map<std::string, sf::SoundBuffer*>();
    std::string ressourceFolder = "ressources/sounds/";
    DIR* dir = NULL;
    struct dirent* currentFile = NULL;
    dir = opendir(ressourceFolder.c_str());
    assert(dir != NULL);
    
    while ((currentFile = readdir(dir)) != NULL) {
        std::string filename(currentFile->d_name);
        if (filename != "." && filename != "..") {
            unsigned found = filename.find_last_of(".");
            std::string filenameWithoutExt = filename.substr(0,found);
            sf::SoundBuffer* buffer = new sf::SoundBuffer();
            buffer->loadFromFile(ressourceFolder + filename);
            assert(buffer);
            this->__sounds->insert(std::pair<std::string, sf::SoundBuffer*>(filenameWithoutExt, buffer));
        }
    }
}

sf::SoundBuffer* Sounds::get(std::string name) {
    assert(this->__sounds->size() > 0);
    return this->__sounds->at(name);
}