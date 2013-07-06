#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <vector>
#include "../GraphicEngine/Elements/Frame.hh"
#include "Elements/Planet.hh"

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
        std::vector<Planet*> __planets;
    };
}
#endif // WORLDENGINE_H
