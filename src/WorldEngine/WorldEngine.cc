#include "WorldEngine.hh"

namespace World {

    WorldEngine::WorldEngine() {
    }

    WorldEngine::~WorldEngine() {
        while (!this->__planets.empty()) {
            this->__planets.pop_back();
        }
    }

    bool choosePosition(int x, int y, std::vector<Planet*> planets) {
        int padding = 100;

        for (Planet* planet : planets) {
            if (((planet->getPosition().getX() < x + padding) && (planet->getPosition().getX() > x - padding)) &&
                    ((planet->getPosition().getY() < y + padding) && (planet->getPosition().getY() > y - padding)))
                return false;
        }
        return true;
    }

    void WorldEngine::initBar() {
        
        int nbPlanets = 0;
        int nbShips = 0;
        
        for (auto planet : this->__planets) {
            if ((planet->getOwner() != NULL) && (planet->getOwner()->getId() == this->__player.getId())) {
                nbPlanets++;
            }
        }
        
        this->__topbar.init();
    
        this->__topbar.getGas()->setValue(std::to_string(this->__player.getNbGas()));
        this->__topbar.getOre()->setValue(std::to_string(this->__player.getNbOre()));
        
        this->__player.setNbPlanets(nbPlanets);
        
        this->__topbar.getEarth()->setValue(std::to_string(this->__player.getNbPlanets()));
        this->__topbar.getShips()->setValue(std::to_string(this->__player.getNbShip()));
        
        this->addComponent(&this->__topbar);
    }
    
    void    WorldEngine::initContextualHUD()
    {
        // side bar
        this->__sidebar.setSize(Tools::Position(300, 748));
        this->__sidebar.setPosition(Tools::Position(748, 40));
        
        this->__sidebar.setBackgroundColor(sf::Color(38, 43, 57));
        this->__sidebar.setOutlineColor(sf::Color(29, 33, 46));
        
        // header
        Graphic::GUI::PanelHeader *planetInfo = new Graphic::GUI::PanelHeader();
        planetInfo->setPlanetIcon("");
        planetInfo->setPlanetName("");
        this->__sidebar.setPanelHeader(&(*planetInfo));
        this->__sidebar.addComponent(&(*planetInfo));
        
        this->addComponent(&this->__sidebar);
        
        Graphic::GUI::Ressource *gasRevenue = new Graphic::GUI::Ressource();
        gasRevenue->setPosition(Tools::Position(768, 170));
        gasRevenue->setValue("");
        gasRevenue->setIcon("gas");
        
        this->__sidebar.getPanelHeader()->setGas(&(*gasRevenue));
        this->__sidebar.getPanelHeader()->addComponent(&(*gasRevenue));
        
        Graphic::GUI::Ressource *mineralsRevenue = new Graphic::GUI::Ressource();
        mineralsRevenue->setPosition(Tools::Position(850, 170));
        mineralsRevenue->setValue("");
        mineralsRevenue->setIcon("minerals");
        
        this->__sidebar.getPanelHeader()->setMinerals(&(*mineralsRevenue));
        this->__sidebar.getPanelHeader()->addComponent(&(*mineralsRevenue));
    }
      
    void WorldEngine::generateWorld(int nbPlanets) {
        srand (time(NULL));
        bool isFirst = true;
        for (int i = 0; i < nbPlanets; i++) {
            Tools::Position position;
            Planet *planet = new Planet();
            if (isFirst)
            {
                planet->setOwner(&(this->__player));
                isFirst = false;
            }
            int x = rand() % 658 + 40;
            int y = rand() % 658 + 40;

            while (!choosePosition(x, y, this->__planets)) {
                x = rand() % 658 + 40;
                y = rand() % 658 + 40;
            }

            position.setX(x);
            position.setY(y);

            planet->setPosition(position);
            planet->setSpriteRatio(0.4);
            planet->setSize(Tools::Position(40, 40));
            planet->setTexture(planet->getTextureName());
            
            this->__planets.push_back(planet);

            std::cout << "Added planet:" << planet->getName() << " x:" << planet->getPosition().getX() << " y: " << planet->getPosition().getY() << std::endl;
        }
    }

    void WorldEngine::init() {
        this->__action.setWorld(this);
        this->__player.setId(1);

        this->generateWorld(10);
        
        // Création de la topbar
        this->initBar();
        // Adding contextual menu
        this->initContextualHUD();

        for (Planet* planet : this->__planets) {
            planet->setEvent(&this->__action);
            this->addComponent(&(*planet));
        }
    }
    
    void WorldEngine::updateContext(Planet *planet)
    {
        this->__sidebar.getPanelHeader()->setPlanetIcon(planet->getTextureName());
        this->__sidebar.getPanelHeader()->setPlanetName(planet->getName());
        this->__sidebar.getPanelHeader()->getMinerals()->setValue(std::to_string(planet->getMineralsRevenue()));
        this->__sidebar.getPanelHeader()->getGas()->setValue(std::to_string(planet->getGasRevenue()));
        
        if (planet->getOwner() != NULL)
        {
            std::cout << "has owner" << std::endl;
        }
    }

    void WorldEngine::setPlayer(Player __player) {
        this->__player = __player;
    }

    Player WorldEngine::getPlayer() const {
        return __player;
    }
}