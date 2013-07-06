#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <vector>
#include "../GraphicEngine/Elements/Frame.hh"
#include "../GraphicEngine/Elements/Panel.hh"
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
        Graphic::GUI::Panel __sidebar;
        WorldAction __action;
        std::vector<Planet*> __planets;
    };
}
#endif // WORLDENGINE_H
