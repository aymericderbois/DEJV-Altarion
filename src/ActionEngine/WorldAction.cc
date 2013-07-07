#include "WorldAction.hh"
#include "../WorldEngine/WorldEngine.hh"
#include "../WorldEngine/Elements/ElementsConfig.hh"

WorldAction::WorldAction() {
}

WorldAction::~WorldAction() {
}

void WorldAction::onCLick(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        // set up contextual menu with clicked content
        if ((planet->getOwner() != NULL) &&
            (this->__world->getCurrentPlanet() != NULL) &&
            (this->__world->getPlayer().getId() == planet->getOwner()->getId()))
            this->__world->getCurrentPlanet()->setBackground("planet-owned");
        else
            this->__world->getCurrentPlanet()->setBackground("planet-enemy");
        
        std::cout << "building context for planet: " << planet->getName() << std::endl;
        this->__world->updateContext(planet);
        planet->setBackground("planet-selected");
        button->fireSound();
    }
    
    if (button->getId() == "ADD_MINE")
    {
        if ((this->__world->getCurrentPlanet()->getOwner() != NULL) &&
            (this->__world->getPlayer().getId() == this->__world->getCurrentPlanet()->getOwner()->getId()))
        {
            if (this->__world->buyMine())
                button->fireSound();
            else
                button->fireSoundError();

        }
    }
    
    if (button->getId() == "ADD_REFINERY")
    {
        if ((this->__world->getCurrentPlanet()->getOwner() != NULL) &&
            (this->__world->getPlayer().getId() == this->__world->getCurrentPlanet()->getOwner()->getId()))
        {
            if (this->__world->buyRefinery())
                button->fireSound();
            else
                button->fireSoundError();

        }
    }
    
    if (button->getId() == "ADD_SHIPYARD")
    {
        if ((this->__world->getCurrentPlanet()->getOwner() != NULL) &&
            (this->__world->getPlayer().getId() == this->__world->getCurrentPlanet()->getOwner()->getId()))
        {
            if (this->__world->buyShipyard())
                button->fireSound();
            else
                button->fireSoundError();
        }
    }
    
    if (button->getId() == "ADD_SHIP")
    {
        if ((this->__world->getCurrentPlanet()->getOwner() != NULL) &&
            (this->__world->getPlayer().getId() == this->__world->getCurrentPlanet()->getOwner()->getId()))
        {
            if (this->__world->buyShip())
                button->fireSound();
            else
                button->fireSoundError();
        }
    }
}

void WorldAction::onHover(EventLauncher *launcher) {
    Graphic::GUI::Button    *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        planet->setBackground("planet-selected");
    }

}

void WorldAction::onUnHover(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    
    
    Planet  *planet = dynamic_cast<Planet*> (launcher);
    
    if (planet != 0) {
        if ((this->__world->getCurrentPlanet() != NULL) &&
            (planet->getName() != this->__world->getCurrentPlanet()->getName()))
        {
            if ((planet->getOwner() != NULL) && (this->__world->getPlayer().getId() == planet->getOwner()->getId()))
                planet->setBackground("planet-owned");
            else
                planet->setBackground("planet-enemy");
        }
    }

}

void WorldAction::setWorld(World::WorldEngine* __world) {
    this->__world = __world;
}

World::WorldEngine* WorldAction::getWorld() const {
    return __world;
}