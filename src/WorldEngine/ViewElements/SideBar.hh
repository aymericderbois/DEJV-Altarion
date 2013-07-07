#ifndef SIDEBAR_HH
#define	SIDEBAR_HH

#include "../../GraphicEngine/Elements/ContextMenu.hh"
#include "../../GraphicEngine/Elements/Ressource.hh"
#include "../../GraphicEngine/Elements/PanelHeader.hh"
#include "../../GraphicEngine/Elements/Label.hh"
#include "../../GraphicEngine/Elements/Button.hh"

#include "../Elements/Planet.hh"
#include "../../ActionEngine/WorldAction.hh"

class SideBar : public Graphic::GUI::ContextMenu
{
public:
    SideBar();
    virtual ~SideBar();
    void init();
    void updateContext(Planet *planet);
private:
    WorldAction               *__action;
    Graphic::GUI::PanelHeader *__header;
    Graphic::GUI::Button      *__mineBtn;
    Graphic::GUI::Button      *__refineryBtn;
    Graphic::GUI::Button      *__shipyardBtn;
    
    Graphic::GUI::Label       *__mineLabel;
    Graphic::GUI::Label       *__refineryLabel;
    Graphic::GUI::Label       *__shipyardLabel;
    
    Graphic::GUI::Button      *__cruiserBtn;
    Graphic::GUI::Label       *__cruiserLabel;
    
public:
    void setPanelHeader (Graphic::GUI::PanelHeader *__header);
    Graphic::GUI::PanelHeader* getPanelHeader();
    
    void setMineBtn (Graphic::GUI::Button *btn);
    Graphic::GUI::Button* getMineBtn();
    
    void setRefineryBtn (Graphic::GUI::Button *btn);
    Graphic::GUI::Button* getRefineryBtn();
    
    void setShipyardBtn (Graphic::GUI::Button *btn);
    Graphic::GUI::Button* getShipyardBtn();
    
    
    void setMineLabel (Graphic::GUI::Label *btn);
    Graphic::GUI::Label* getMineLabel();
    
    void setRefineryLabel (Graphic::GUI::Label *btn);
    Graphic::GUI::Label* getRefineryLabel();
    
    void setShipyardLabel (Graphic::GUI::Label *btn);
    Graphic::GUI::Label* getShipyardLabel();
    
    void setAction(WorldAction *action) { this->__action = action;}
};

#endif	/* SIDEBAR_HH */

