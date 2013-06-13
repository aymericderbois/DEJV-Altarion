#ifndef EVENTLISTENER_HH
#define	EVENTLISTENER_HH

#include <map>
#include <iostream>
#include <functional>

#include "Event.hh"

class EventListener {
public:
    EventListener();
    virtual ~EventListener();
private:
    std::map<std::string, std::function<void(Event event)> > implementedEvents;

};

#endif	/* EVENTLISTENER_HH */

