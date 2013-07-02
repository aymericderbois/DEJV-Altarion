#ifndef EVENTLISTENER_HH
#define	EVENTLISTENER_HH

#include <map>
#include <iostream>
#include <functional>

#include "EventLauncher.hh"

class EventListener {
public:
    EventListener();
    virtual void eventPerform(EventLauncher *launcher, int identifier) = 0;
    virtual ~EventListener();

};

#endif	/* EVENTLISTENER_HH */

