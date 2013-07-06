#ifndef TOPBAR_HH
#define	TOPBAR_HH

#include "../../GraphicEngine/Elements/Panel.hh"
#include "../../GraphicEngine/Elements/Ressource.hh"

class TopBar : public Graphic::GUI::Panel{
public:
    TopBar();
    virtual ~TopBar();
    void init();
private:
    Graphic::GUI::Ressource *__gas;
    Graphic::GUI::Ressource *__ore;
    Graphic::GUI::Ressource *__ships;
    Graphic::GUI::Ressource *__earth;
public:
    Graphic::GUI::Ressource* getGas();
    void setGas(Graphic::GUI::Ressource *gas);
    
    Graphic::GUI::Ressource* getOre();
    void setOre(Graphic::GUI::Ressource *ore);
    
    Graphic::GUI::Ressource* getShips();
    void setShips(Graphic::GUI::Ressource *ships);
    
    Graphic::GUI::Ressource* getEarth();
    void setEarth(Graphic::GUI::Ressource *earth);
};

#endif	/* TOPBAR_HH */

