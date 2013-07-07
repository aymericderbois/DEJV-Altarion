#include "SideBar.hh"

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
    mineralsRevenue->setPosition(Tools::Position(900, 170));
    mineralsRevenue->setValue("");
    mineralsRevenue->setIcon("minerals");
    
    this->getPanelHeader()->setMinerals(&(*mineralsRevenue));
    this->getPanelHeader()->addComponent(&(*mineralsRevenue));
    
    
    // MINES
    Graphic::GUI::Button    *mineBtn = new Graphic::GUI::Button();
    mineBtn->setPosition(Tools::Position(768, 270));
    mineBtn->setSpriteRatio(0.7);
    mineBtn->setSize(Tools::Position(150, 100));
    mineBtn->setEvent(this->__action);
    mineBtn->setId("ADD_MINE");
    this->setMineBtn(&(*mineBtn));
    this->addComponent(&(*mineBtn));
    
    Graphic::GUI::Label    *mineLbl = new Graphic::GUI::Label();
    mineLbl->setText("");
    mineLbl->setFont("biting.ttf");
    mineLbl->setPosition(Tools::Position(788, 330));
    this->setMineLabel(&(*mineLbl));
    this->addComponent(&(*mineLbl));
    
    Graphic::GUI::Ressource *minesOreCost = new Graphic::GUI::Ressource();
    minesOreCost->setPosition(Tools::Position(900, 270));
    minesOreCost->setValue(std::to_string(MINE_COST_MINERALS));
    minesOreCost->setIcon("minerals");
    this->addComponent(&(*minesOreCost));
    
    Graphic::GUI::Ressource *minesGasCost = new Graphic::GUI::Ressource();
    minesGasCost->setPosition(Tools::Position(900, 305));
    minesGasCost->setValue(std::to_string(MINE_COST_GAS));
    minesGasCost->setIcon("gas");
    this->addComponent(&(*minesGasCost));
    
    // REFINERIES
    Graphic::GUI::Button    *refineryBtn = new Graphic::GUI::Button();
    refineryBtn->setPosition(Tools::Position(768, 380));
    refineryBtn->setSize(Tools::Position(150, 100));
    refineryBtn->setSpriteRatio(0.7);
    refineryBtn->setEvent(this->__action);
    refineryBtn->setId("ADD_REFINERY");
    this->setRefineryBtn(&(*refineryBtn));
    this->addComponent(&(*refineryBtn));
    
    Graphic::GUI::Label    *refineryLbl = new Graphic::GUI::Label();
    refineryLbl->setText("");
    refineryLbl->setFont("biting.ttf");
    refineryLbl->setPosition(Tools::Position(788, 440));
    this->setRefineryLabel(&(*refineryLbl));
    this->addComponent(&(*refineryLbl));
    
    Graphic::GUI::Ressource *refineriesOreCost = new Graphic::GUI::Ressource();
    refineriesOreCost->setPosition(Tools::Position(900, 380));
    refineriesOreCost->setValue(std::to_string(REFINERY_COST_MINERALS));
    refineriesOreCost->setIcon("minerals");
    this->addComponent(&(*refineriesOreCost));
    
    Graphic::GUI::Ressource *refineriesGasCost = new Graphic::GUI::Ressource();
    refineriesGasCost->setPosition(Tools::Position(900, 415));
    refineriesGasCost->setValue(std::to_string(REFINERY_COST_GAS));
    refineriesGasCost->setIcon("gas");
    this->addComponent(&(*refineriesGasCost));
    
    
    // SHIPYARDS
    Graphic::GUI::Button    *shipyardBtn = new Graphic::GUI::Button();
    shipyardBtn->setPosition(Tools::Position(768, 490));
    shipyardBtn->setSize(Tools::Position(150, 100));
    shipyardBtn->setSpriteRatio(0.7);
    shipyardBtn->setEvent(this->__action);
    shipyardBtn->setId("ADD_SHIPYARD");
    this->setShipyardBtn(&(*shipyardBtn));
    this->addComponent(&(*shipyardBtn));
    
    Graphic::GUI::Label    *shipyardLbl = new Graphic::GUI::Label();
    shipyardLbl->setText("");
    shipyardLbl->setFont("biting.ttf");
    shipyardLbl->setPosition(Tools::Position(788, 555));
    this->setShipyardLabel(&(*shipyardLbl));
    this->addComponent(&(*shipyardLbl));
    
    Graphic::GUI::Ressource *shipyardOreCost = new Graphic::GUI::Ressource();
    shipyardOreCost->setPosition(Tools::Position(900, 490));
    shipyardOreCost->setValue(std::to_string(SHIPYARD_COST_MINERALS));
    shipyardOreCost->setIcon("minerals");
    this->addComponent(&(*shipyardOreCost));
    
    Graphic::GUI::Ressource *shipyardGasCost = new Graphic::GUI::Ressource();
    shipyardGasCost->setPosition(Tools::Position(900, 525));
    shipyardGasCost->setValue(std::to_string(SHIPYARD_COST_GAS));
    shipyardGasCost->setIcon("gas");
    this->addComponent(&(*shipyardGasCost));
    
    
    // CRUISERS
    Graphic::GUI::Button    *cruiserBtn = new Graphic::GUI::Button();
    cruiserBtn->setPosition(Tools::Position(768, 600));
    cruiserBtn->setSize(Tools::Position(150, 100));
    cruiserBtn->setSpriteRatio(0.7);
    cruiserBtn->setEvent(this->__action);
    cruiserBtn->setId("ADD_SHIP");
    this->__cruiserBtn = &(*cruiserBtn);
    this->addComponent(&(*cruiserBtn));
    
    Graphic::GUI::Label    *cruiserLbl = new Graphic::GUI::Label();
    cruiserLbl->setText("");
    cruiserLbl->setFont("biting.ttf");
    cruiserLbl->setPosition(Tools::Position(788, 650));
    this->__cruiserLabel = &(*cruiserLbl);
    this->addComponent(&(*cruiserLbl));
    
    Graphic::GUI::Ressource *cruiserOreCost = new Graphic::GUI::Ressource();
    cruiserOreCost->setPosition(Tools::Position(900, 600));
    cruiserOreCost->setValue(std::to_string(CRUISER_COST_MINERALS));
    cruiserOreCost->setIcon("minerals");
    this->addComponent(&(*cruiserOreCost));
    
    Graphic::GUI::Ressource *cruiserGasCost = new Graphic::GUI::Ressource();
    cruiserGasCost->setPosition(Tools::Position(900, 635));
    cruiserGasCost->setValue(std::to_string(CRUISER_COST_GAS));
    cruiserGasCost->setIcon("gas");
    this->addComponent(&(*cruiserGasCost));
}

void SideBar::updateContext(Planet *planet)
{
    this->getPanelHeader()->setPlanetIcon(planet->getTextureName());
    this->getPanelHeader()->setPlanetName(planet->getName());
    this->getPanelHeader()->getMinerals()->setValue(std::to_string(planet->getMineralsRevenue()));
    this->getPanelHeader()->getGas()->setValue(std::to_string(planet->getGasRevenue()));
    
    
    this->__mineBtn->setTexture("mine");
    this->__refineryBtn->setTexture("refinery");
    this->__shipyardBtn->setTexture("shipyard");
    this->__cruiserBtn->setTexture("cruiser");
    
    this->getMineLabel()->setText(std::to_string(planet->getMines()) + " / " + std::to_string(planet->getMaxMines()));
    this->getRefineryLabel()->setText(std::to_string(planet->getRefineries()) + " / " + std::to_string(planet->getMaxRefineries()));
    this->getShipyardLabel()->setText(std::to_string(planet->getShipyards()) + " / " + std::to_string(planet->getMaxShipyards()));
    
    int nbShips = 0;
    if (planet->getFleet() != NULL)
        nbShips = planet->getFleet()->getShips().size();
    this->__cruiserLabel->setText(std::to_string(nbShips));
    
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