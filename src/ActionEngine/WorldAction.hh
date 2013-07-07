#ifndef WORLDACTION_HH
#define	WORLDACTION_HH

#include "../GraphicEngine/Elements/Button.hh"
#include "../libs/Event/EventListener.hh"
#include "../libs/Event/EventLauncher.hh"

namespace World {
    class WorldEngine;
}

class WorldAction : public EventListener {
public:
    WorldAction();
    virtual ~WorldAction();
public:
    void onCLick(EventLauncher *launcher, int buttonClick);
    void onHover(EventLauncher *launcher);
    void onUnHover(EventLauncher *launcher);
private:
    World::WorldEngine* __world;
    
public:
    void setWorld(World::WorldEngine* __world);
    World::WorldEngine* getWorld() const;

};

#endif	/* WORLDACTION_HH */

