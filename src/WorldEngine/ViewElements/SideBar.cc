#include "SideBar.hh"
#include "../../ActionEngine/MenuAction.hh"

SideBar::SideBar() {
}

SideBar::~SideBar() {
}

void SideBar::init() {
    // side bar
    this->setSize(Tools::Position(300, 748));
    this->setPosition(Tools::Position(748, 40));
    
    this->setBackgroundColor(sf::Color(38, 43, 57));
    this->setOutlineColor(sf::Color(29, 33, 46));
    
    // header
    Graphic::GUI::PanelHeader *planetInfo = new Graphic::GUI::PanelHeader();
    planetInfo->setPlanetIcon("");
    planetInfo->setPlanetName("");
    this->setPanelHeader(&(*planetInfo));
    this->addComponent(&(*planetInfo));
    
    Graphic::GUI::Ressource *gasRevenue = new Graphic::GUI::Ressource();
    gasRevenue->setPosition(Tools::Position(768, 170));
    gasRevenue->setValue("");
    gasRevenue->setIcon("gas");
    
    this->getPanelHeader()->setGas(&(*gasRevenue));
    this->getPanelHeader()->addComponent(&(*gasRevenue));
    
    Graphic::GUI::Ressource *mineralsRevenue = new Graphic::GUI::Ressource();
    mineralsRevenue->setPosition(Tools::Position(850, 170));
    mineralsRevenue->setValue("");
    mineralsRevenue->setIcon("minerals");
    
    this->getPanelHeader()->setMinerals(&(*mineralsRevenue));
    this->getPanelHeader()->addComponent(&(*mineralsRevenue));
    
    
    // add buttons
    Graphic::GUI::Button    *mineBtn = new Graphic::GUI::Button();
    mineBtn->setTexture("mine");
    mineBtn->setPosition(Tools::Position(768, 270));
    mineBtn->setSpriteRatio(0.7);
    mineBtn->setSize(Tools::Position(150, 100));
    mineBtn->setEvent(new MenuAction());
    this->setMineBtn(&(*mineBtn));
    this->addComponent(&(*mineBtn));
    
    Graphic::GUI::Label    *mineLbl = new Graphic::GUI::Label();
    mineLbl->setText("");
    mineLbl->setFont("biting.ttf");
    mineLbl->setPosition(Tools::Position(900, 270));
    this->setMineLabel(&(*mineLbl));
    this->addComponent(&(*mineLbl));
    
    Graphic::GUI::Button    *refineryBtn = new Graphic::GUI::Button();
    refineryBtn->setTexture("refinery");
    refineryBtn->setPosition(Tools::Position(768, 380));
    refineryBtn->setSize(Tools::Position(150, 100));
    refineryBtn->setSpriteRatio(0.7);
    refineryBtn->setEvent(new MenuAction());
    this->setRefineryBtn(&(*refineryBtn));
    this->addComponent(&(*refineryBtn));
    
    Graphic::GUI::Label    *refineryLbl = new Graphic::GUI::Label();
    refineryLbl->setText("");
    refineryLbl->setFont("biting.ttf");
    refineryLbl->setPosition(Tools::Position(900, 380));
    this->setRefineryLabel(&(*refineryLbl));
    this->addComponent(&(*refineryLbl));
    
    Graphic::GUI::Button    *shipyardBtn = new Graphic::GUI::Button();
    shipyardBtn->setTexture("shipyard");
    shipyardBtn->setPosition(Tools::Position(768, 490));
    shipyardBtn->setSize(Tools::Position(150, 100));
    shipyardBtn->setSpriteRatio(0.7);
    shipyardBtn->setEvent(new MenuAction());
    this->setShipyardBtn(&(*shipyardBtn));
    this->addComponent(&(*shipyardBtn));
    
    Graphic::GUI::Label    *shipyardLbl = new Graphic::GUI::Label();
    shipyardLbl->setText("");
    shipyardLbl->setFont("biting.ttf");
    shipyardLbl->setPosition(Tools::Position(900, 490));
    this->setShipyardLabel(&(*shipyardLbl));
    this->addComponent(&(*shipyardLbl));
}

void SideBar::updateContext(Planet *planet)
{
    this->getPanelHeader()->setPlanetIcon(planet->getTextureName());
    this->getPanelHeader()->setPlanetName(planet->getName());
    this->getPanelHeader()->getMinerals()->setValue(std::to_string(planet->getMineralsRevenue()));
    this->getPanelHeader()->getGas()->setValue(std::to_string(planet->getGasRevenue()));
    
    this->getMineLabel()->setText(std::to_string(planet->getMines()) + " / " + std::to_string(planet->getMaxMines()));
    this->getRefineryLabel()->setText(std::to_string(planet->getRefineries()) + " / " + std::to_string(planet->getMaxRefineries()));
    this->getShipyardLabel()->setText(std::to_string(planet->getShipyards()) + " / " + std::to_string(planet->getMaxShipyards()));
    
}


void SideBar::setPanelHeader (Graphic::GUI::PanelHeader* __header)
{
    this->__header = __header;
}

Graphic::GUI::PanelHeader* SideBar::getPanelHeader()
{
    return this->__header;
}

void SideBar::setMineBtn (Graphic::GUI::Button *btn)
{
    this->__mineBtn = btn;
}

Graphic::GUI::Button* SideBar::getMineBtn()
{
    return this->__mineBtn;
}

void SideBar::setRefineryBtn (Graphic::GUI::Button *btn)
{
    this->__refineryBtn = btn;
}

Graphic::GUI::Button* SideBar::getRefineryBtn()
{
    return this->__refineryBtn;
}

void SideBar::setShipyardBtn (Graphic::GUI::Button *btn)
{
    this->__shipyardBtn = btn;
}

Graphic::GUI::Button* SideBar::getShipyardBtn()
{
    return this->__shipyardBtn;
}


void SideBar::setMineLabel (Graphic::GUI::Label *btn)
{
    this->__mineLabel = btn;
}

Graphic::GUI::Label* SideBar::getMineLabel()
{
    return this->__mineLabel;
}

void SideBar::setRefineryLabel (Graphic::GUI::Label *btn)
{
    this->__refineryLabel = btn;
}

Graphic::GUI::Label* SideBar::getRefineryLabel()
{
    return this->__refineryLabel;
}

void SideBar::setShipyardLabel (Graphic::GUI::Label *btn)
{
    this->__shipyardLabel = btn;
}

Graphic::GUI::Label* SideBar::getShipyardLabel()
{
    return this->__shipyardLabel;
}