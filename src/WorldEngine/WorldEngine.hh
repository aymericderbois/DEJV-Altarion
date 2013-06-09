#ifndef WORLDENGINE_H
#define WORLDENGINE_H

#include <list>
#include "Elements/Planet.hh"

namespace World
{
    class WorldEngine
    {
    public:
        WorldEngine();
    private:
        std::list<Planet*> __planets;
    };
}
#endif // WORLDENGINE_H
