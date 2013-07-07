#include "Music.hh"
#include <dirent.h>
#include <assert.h>

Musics::Musics() {
}

Musics::~Musics() {
}

Musics& Musics::getInstance() {
    static Musics instance;
    return instance;
}

void Musics::loadAllMusics() {
    this->__musics = new std::map<std::string, sf::Music*>();
    std::string ressourceFolder = "ressources/musics/";
    DIR* dir = NULL;
    struct dirent* currentFile = NULL;
    dir = opendir(ressourceFolder.c_str());
    assert(dir != NULL);
    
    while ((currentFile = readdir(dir)) != NULL) {
        std::string filename(currentFile->d_name);
        if (filename != "." && filename != "..") {
            unsigned found = filename.find_last_of(".");
            std::string filenameWithoutExt = filename.substr(0,found);
            sf::Music* buffer = new sf::Music();
            buffer->openFromFile(ressourceFolder + filename);
            assert(buffer);
            this->__musics->insert(std::pair<std::string, sf::Music*>(filenameWithoutExt, buffer));
        }
    }
}

sf::Music* Musics::get(std::string name) {
    assert(this->__musics->size() > 0);
    return this->__musics->at(name);
}