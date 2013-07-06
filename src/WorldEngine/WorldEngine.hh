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
    private:
        TopBar __topbar;
        Graphic::GUI::ContextMenu __sidebar;
        Player __player;
        WorldAction __action;
        std::vector<Planet*> __planets;
    public:
        void updateContext(Planet   *planet);
        void setPlayer(Player __player);
        Player getPlayer() const;
    };
}
#endif // WORLDENGINE_H
