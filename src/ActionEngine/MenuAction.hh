/* 
 * File:   MenuAction.hh
 * Author: Aymeric
 *
 * Created on 2 juillet 2013, 14:29
 */

#ifndef MENUACTION_HH
#define	MENUACTION_HH

#include "../libs/Event/EventListener.hh"
#include "../libs/Event/EventLauncher.hh"


class MenuAction: public EventListener {
public:
    MenuAction();
    virtual ~MenuAction();
public:
    void eventPerform(EventLauncher *launcher, int identifier);
        
private:

};

#endif	/* MENUACTION_HH */

