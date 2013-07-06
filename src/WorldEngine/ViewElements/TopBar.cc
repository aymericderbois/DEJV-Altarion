#include "TopBar.hh"

TopBar::TopBar() {
}

TopBar::~TopBar() {
}

void TopBar::init() {
    this->setSize(Tools::Position(1024, 40));
    this->setPosition(Tools::Position(0, 0));
    this->setBackgroundColor(sf::Color(38, 43, 57));

    Graphic::GUI::Ressource *gas = new Graphic::GUI::Ressource();
    gas->setPosition(Tools::Position(30, 5));
    gas->setValue("0");
    gas->setIcon("gas");
    this->__gas = &(*gas);
    this->addComponent(gas);

    Graphic::GUI::Ressource *minerals = new Graphic::GUI::Ressource();
    minerals->setPosition(Tools::Position(180, 5));
    minerals->setValue("0");
    minerals->setIcon("minerals");
    this->__ore = &(*minerals);
    this->addComponent(minerals);

    Graphic::GUI::Ressource *ships = new Graphic::GUI::Ressource();
    ships->setPosition(Tools::Position(330, 5));
    ships->setValue("0");
    ships->setIcon("ship");
    this->__ships = &(*ships);
    this->addComponent(ships);

    Graphic::GUI::Ressource *earth = new Graphic::GUI::Ressource();
    earth->setPosition(Tools::Position(480, 5));
    earth->setValue("0");
    earth->setIcon("earth");
    this->__earth = &(*earth);
    this->addComponent(earth);
}

Graphic::GUI::Ressource* TopBar::getGas()
{
    return this->__gas;
}

void TopBar::setGas(Graphic::GUI::Ressource *gas)
{
    this->__gas = gas;
}

Graphic::GUI::Ressource* TopBar::getOre()
{
    return this->__ore;
}

void TopBar::setOre(Graphic::GUI::Ressource *ore)
{
    this->__ore = ore;
}

Graphic::GUI::Ressource* TopBar::getShips()
{
    return this->__ships;
}

void TopBar::setShips(Graphic::GUI::Ressource *ships)
{
    this->__ships = ships;
}

Graphic::GUI::Ressource* TopBar::getEarth()
{
    return this->__earth;
}

void TopBar::setEarth(Graphic::GUI::Ressource *earth)
{
    this->__earth = earth;
}
