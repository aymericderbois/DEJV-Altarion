#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <vector>
#include "../GraphicEngine/Elements/Frame.hh"
#include "../GraphicEngine/Elements/Panel.hh"
#include "../GraphicEngine/Elements/ContextMenu.hh"
#include "../GraphicEngine/Elements/Ressource.hh"
#include "Elements/Planet.hh"
#include "../ActionEngine/WorldAction.hh"
#include "../Tools/Position.hh"

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
        Graphic::GUI::Panel __topbar;
        Graphic::GUI::ContextMenu __sidebar;
        WorldAction __action;
        std::vector<Planet*> __planets;
    public:
        void updateContext(Planet   *planet);
    };
}
#endif // WORLDENGINE_H
