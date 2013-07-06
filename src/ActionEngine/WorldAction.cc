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
        updateContextMenuContent(planet);
    }
    
    std::cout << "On click" << std::endl;
    std::cout << this->__world->getComponents().size() << std::endl;
}

void WorldAction::onHover(EventLauncher *launcher) {
    Graphic::GUI::Button    *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    std::cout << "On hover" << std::endl;

}

void WorldAction::onUnHover(EventLauncher *launcher) {
    Graphic::GUI::Button *button = dynamic_cast<Graphic::GUI::Button*> (launcher);
    std::cout << "On unhover" << std::endl;

}

void WorldAction::setWorld(World::WorldEngine* __world) {
    this->__world = __world;
}

World::WorldEngine* WorldAction::getWorld() const {
    return __world;
}

void            WorldAction::updateContextMenuContent(Planet    *planet)
{
    std::cout << "building context for planet: " << planet->getName() << std::endl;
    
    
}