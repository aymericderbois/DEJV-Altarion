#include "Planet.hh"

Planet::Planet() {

    //init buildings settings
    this->__max_mines = rand() % 20 + 2;
    this->__max_refineries = rand() % 20 + 2;
    this->__max_shipyards = rand() % 10 + 1;

    this->__mines = 0;
    this->__refineries = 0;
    this->__shipyards = 0;

    this->__fleet = NULL;
    this->__owner = NULL;

    std::stringstream name;
    name << "P";
    name << rand() % 9 + 0;
    name << "X";
    name << rand() % 999 + 0;

    this->setName(name.str());
    this->setTextureName(chooseTexture());
}

Planet::~Planet() {
    if (this->__fleet != NULL) {
        delete this->__fleet;
    }
}

std::string Planet::getName() {
    return this->__name;
}

void Planet::setName(std::string name) {
    this->__name = name;
}

std::string Planet::getTextureName() {
    return this->__textureName;
}

void Planet::setTextureName(std::string texturename) {
    this->__textureName = texturename;
}

int             Planet::getGasRevenue()
{
    return BASE_REVENUE_GAS + (BASE_REVENUE_GAS * (this->__refineries));
}

int             Planet::getMineralsRevenue()
{
    return BASE_REVENUE_MINERALS + (BASE_REVENUE_MINERALS * (this->__mines));
}

Player*         Planet::getOwner()
{
    return this->__owner;
}

void            Planet::setOwner(Player* owner)
{
    this->__owner = owner;
}

std::string     chooseTexture()
{
    int     textureNumber = rand() % 11 + 1;
    
    switch (textureNumber) {
        case 1: return "1-Earth"; break;
        case 2: return "1-Mars"; break;
        case 3: return "Brightmoon"; break;
        case 4: return "Bul"; break;
        case 5: return "Darkmoon"; break;
        case 6: return "Jupiter"; break;
        case 7: return "Kahless"; break;
        case 8: return "Saturn"; break;
        case 9: return "Sporl"; break;
        case 10: return "Tor"; break;
        case 11: return "Uranus"; break;
            
        default:return "1-Earth";break;
    }
}