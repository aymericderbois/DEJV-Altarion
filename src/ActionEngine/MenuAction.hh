/* 
 * File:   MenuAction.hh
 * Author: Aymeric
 *
 * Created on 2 juillet 2013, 14:29
 */

#ifndef MENUACTION_HH
#define	MENUACTION_HH

#include "../GraphicEngine/Elements/Button.hh"
#include "../libs/Event/EventListener.hh"
#include "../libs/Event/EventLauncher.hh"

class MenuAction : public EventListener {
public:
    MenuAction();
    virtual ~MenuAction();
public:
    void onCLick(EventLauncher *launcher);
    void onHover(EventLauncher *launcher);
    void onUnHover(EventLauncher *launcher);
    
private:

};

#endif	/* MENUACTION_HH */

