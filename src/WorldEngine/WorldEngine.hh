#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <vector>
#include "../GraphicEngine/Elements/Frame.hh"
#include "../GraphicEngine/Elements/Panel.hh"
#include "../GraphicEngine/Elements/Label.hh"
#include "../GraphicEngine/Elements/ContextMenu.hh"
#include "../GraphicEngine/Elements/Ressource.hh"

#include "Elements/Planet.hh"
#include "../ActionEngine/WorldAction.hh"
#include "../Tools/Position.hh"
#include "Player.hh"
#include "ViewElements/TopBar.hh"
#include "ViewElements/SideBar.hh"

namespace World
{
    class WorldEngine : public Graphic::GUI::Frame
    {
    public:
        WorldEngine();
        ~WorldEngine();
        void initBar();
        void initContextualHUD();
        void generateWorld(int nbPlanets);
        void init();
        void draw(sf::RenderWindow* window);
        void update();
        void addFleetInMove(Fleet* fleet);
    private:
        TopBar __topbar;
        SideBar __sidebar;
        Player __player;
        WorldAction __action;
        Planet*              __currentPlanet;
        std::vector<Planet*> __planets;
        std::vector<Fleet*> __fleetInMove;
    public:
        void updateContext(Planet   *planet);
        void setPlayer(Player __player);
        Player getPlayer();
        void updateTopBarValues();
        Planet* getCurrentPlanet() { return this->__currentPlanet;}
        void setCurrentPlanet(Planet* planet) { this->__currentPlanet = planet;}
        void buyMine();
        void buyRefinery();
        void buyShipyard();
        void buyShip();
    };
}
#endif // WORLDENGINE_H
