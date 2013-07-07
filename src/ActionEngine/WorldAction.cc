#include "WorldAction.hh"
#include "../WorldEngine/WorldEngine.hh"

WorldAction::WorldAction() {
}

WorldAction::~WorldAction() {
}

void WorldAction::onCLick(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        // set up contextual menu with clicked content
        if ((planet->getOwner() != NULL) && (this->__world->getPlayer().getId() == planet->getOwner()->getId()))
            this->__world->getCurrentPlanet()->setBackground("planet-owned");
        else
            this->__world->getCurrentPlanet()->setBackground("planet-enemy");
        
        std::cout << "building context for planet: " << planet->getName() << std::endl;
        this->__world->updateContext(planet);
        planet->setBackground("planet-selected");
    }
    
    std::cout << "On click" << std::endl;
    std::cout << this->__world->getComponents().size() << std::endl;
}

void WorldAction::onHover(EventLauncher *launcher) {
    Graphic::GUI::Button    *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        planet->setBackground("planet-selected");
    }
    
    std::cout << "On hover" << std::endl;

}

void WorldAction::onUnHover(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        if (planet->getName() != this->__world->getCurrentPlanet()->getName())
        {
            if ((planet->getOwner() != NULL) && (this->__world->getPlayer().getId() == planet->getOwner()->getId()))
                planet->setBackground("planet-owned");
            else
                planet->setBackground("planet-enemy");
        }
    }
    
    std::cout << "On unhover" << std::endl;

}

void WorldAction::setWorld(World::WorldEngine* __world) {
    this->__world = __world;
}

World::WorldEngine* WorldAction::getWorld() const {
    return __world;
}