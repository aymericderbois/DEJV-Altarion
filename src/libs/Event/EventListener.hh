#ifndef EVENTLISTENER_HH
#define	EVENTLISTENER_HH

#include <map>
#include <iostream>
#include <functional>

#include "EventLauncher.hh"

class EventListener {
public:
    EventListener();
    virtual void onCLick(EventLauncher *launcher, int buttonClick) = 0;
    virtual void onHover(EventLauncher *launcher) = 0;
    virtual void onUnHover(EventLauncher *launcher) = 0;
    virtual ~EventListener();

};

#endif	/* EVENTLISTENER_HH */

