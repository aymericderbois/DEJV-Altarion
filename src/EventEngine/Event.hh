#ifndef EVENT_HH
#define	EVENT_HH

#include <iostream>

class Event {
public:
    Event();
    virtual ~Event();
private:
    std::string name;
};

#endif	/* EVENT_HH */

