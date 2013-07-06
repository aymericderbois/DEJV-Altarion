#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <vector>
#include "../GraphicEngine/Elements/Frame.hh"
#include "Elements/Planet.hh"
#include "../ActionEngine/WorldAction.hh"

namespace World
{
    class WorldEngine : public Graphic::GUI::Frame
    {
    public:
        WorldEngine();
        ~WorldEngine();
        void generateWorld(int nbPlanets);
        void init();
    private:
        WorldAction __action;
        std::vector<Planet*> __planets;
    };
}
#endif // WORLDENGINE_H
