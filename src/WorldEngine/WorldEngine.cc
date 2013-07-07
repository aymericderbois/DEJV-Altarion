#include "WorldEngine.hh"
#include "../ActionEngine/MenuAction.hh"
#include "Elements/Ship.hh"
#include <math.h> 

namespace World {

    WorldEngine::WorldEngine() {
    }

    WorldEngine::~WorldEngine() {
        while (!this->__planets.empty()) {
            this->__planets.pop_back();
        }
    }

     /**
     * Fonction appellé à chaque rafraichissement de l'application
     * On s'en sert pour afficher le déplacement des vaisseaux
     */
    void WorldEngine::draw(sf::RenderWindow* window) {
        Graphic::GUI::Frame::draw(window);
        for (Fleet* f : this->__fleetInMove) {
            Tools::Position* pos = f->getCurrent();
            sf::CircleShape shape(5);
            shape.setPosition(pos->getX(), pos->getY());
            window->draw(shape);
        }
    }
    
    /**
     * Fonction appellé à chaque rafraichissement de l'application
     * après l'affichage
     * On s'en sert pour calculer le déplacement des vaisseaux
     */
    void WorldEngine::update() {
        // On déplace les flottes
        //std::cout << "worldEngine update" << std::endl;
        for (Fleet* f : this->__fleetInMove) {
            Tools::Position* pos = f->getCurrent();
            Tools::Position* dest = f->getDestination();

            int directionX = 1, directionY = 1;
            if (pos->getX() > dest->getX()) directionX = -1;
            if (pos->getY() > dest->getY()) directionY = -1;

            if (pos->getX() != dest->getX())
                pos->setX(pos->getX() + directionX);
            if (pos->getY() != dest->getY())
                pos->setY(pos->getY() + directionY);
            
            // La flotte est arrivé
            if (pos->getX() == dest->getX() && pos->getY() == dest->getY()) {
                f->getPlanetDestination()->setFleet(f);
                this->__fleetInMove.erase(std::remove(
                        __fleetInMove.begin(), __fleetInMove.end(), f), __fleetInMove.end());
                f->moveEnded();
            }
 
        }
        
        updateTopBarValues();
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
        this->__topbar.init();
        this->updateTopBarValues();
        this->addComponent(&this->__topbar);
    }

    void WorldEngine::initContextualHUD() {
        WorldAction *action = new WorldAction();
        action->setWorld(this);
        this->__sidebar.setAction(&(*action));
        this->__sidebar.init();
        this->addComponent(&this->__sidebar);
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
                planet->setBackground("planet-owned");
                this->setCurrentPlanet(planet);
                isFirst = false;
            }
            else
                planet->setBackground("planet-enemy");
            
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
            planet->setSize(Tools::Position(50, 50));
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

    void WorldEngine::addFleetInMove(Fleet* fleet) {
        this->__fleetInMove.push_back(fleet);
    }

    void WorldEngine::updateContext(Planet *planet)
    {
        this->__sidebar.updateContext(planet);
        this->setCurrentPlanet(planet);
        
    }

    void WorldEngine::setPlayer(Player __player) {
        this->__player = __player;
    }

    Player WorldEngine::getPlayer() {
        return __player;
    }
    
    void WorldEngine::updateTopBarValues()
    {
        int nbPlanets = 0;
        int nbShips = 0;
        
        float gasRevenue = 0.f;
        float oreRevenue = 0.f;
        
        for (auto planet : this->__planets) {
            if ((planet->getOwner() != NULL) && (planet->getOwner()->getId() == this->__player.getId())) {
                nbPlanets++;
                gasRevenue += planet->getGasRevenue();
                oreRevenue += planet->getMineralsRevenue();
                
                if ((planet->getFleet() != NULL))
                    nbShips += planet->getFleet()->getShips().size();
            }
        }
        
        this->__player.setNbPlanets(nbPlanets);
        this->__player.setNbShip(nbShips);
        this->__player.setNbGas(this->__player.getNbGas() + (gasRevenue * REVENUE_RATE ));
        this->__player.setNbOre(this->__player.getNbOre() + (oreRevenue * REVENUE_RATE ));
        
        this->__topbar.getGas()->setValue(std::to_string((int) floor(this->__player.getNbGas() + 0.5)));
        this->__topbar.getOre()->setValue(std::to_string((int) floor(this->__player.getNbOre() + 0.5)));
        
        this->__topbar.getEarth()->setValue(std::to_string(this->__player.getNbPlanets()));
        this->__topbar.getShips()->setValue(std::to_string(this->__player.getNbShip()));
    }
    
    bool WorldEngine::buyMine()
    {
        if (this->getCurrentPlanet()->getMaxMines() >
            this->getCurrentPlanet()->getMines())
        {
            if ((this->__player.getNbOre() > MINE_COST_MINERALS) &&
                (this->__player.getNbGas() > MINE_COST_GAS))
            {
                float   ore = this->__player.getNbOre() - MINE_COST_MINERALS;
                float   gas = this->__player.getNbGas() - MINE_COST_GAS;
                
                this->__player.setNbGas(gas);
                this->__player.setNbOre(ore);
                
                this->getCurrentPlanet()->setMines(this->getCurrentPlanet()->getMines() + 1);
                this->updateContext(this->getCurrentPlanet());
                return true;
            }
        }
        return false;
    }
    
    bool WorldEngine::buyRefinery()
    {
        if (this->getCurrentPlanet()->getMaxRefineries() >
            this->getCurrentPlanet()->getRefineries())
        {
            if ((this->__player.getNbOre() > REFINERY_COST_MINERALS) &&
                (this->__player.getNbGas() > REFINERY_COST_GAS))
            {
                float   ore = this->__player.getNbOre() - REFINERY_COST_MINERALS;
                float   gas = this->__player.getNbGas() - REFINERY_COST_GAS;
                
                this->__player.setNbGas(gas);
                this->__player.setNbOre(ore);
                
                this->getCurrentPlanet()->setRefineries(this->getCurrentPlanet()->getRefineries() + 1);
                
                this->updateContext(this->getCurrentPlanet());
                
                return true;
            }
        }
        return false;
    }
    
    bool WorldEngine::buyShipyard()
    {
        if (this->getCurrentPlanet()->getMaxShipyards() >
            this->getCurrentPlanet()->getShipyards())
        {
            if ((this->__player.getNbOre() > SHIPYARD_COST_MINERALS) &&
                (this->__player.getNbGas() > SHIPYARD_COST_GAS))
            {
                float   ore = this->__player.getNbOre() - SHIPYARD_COST_MINERALS;
                float   gas = this->__player.getNbGas() - SHIPYARD_COST_GAS;
                
                this->__player.setNbGas(gas);
                this->__player.setNbOre(ore);
                
                this->getCurrentPlanet()->setShipyards(this->getCurrentPlanet()->getShipyards() + 1);
                
                this->updateContext(this->getCurrentPlanet());
                
                return true;
            }
        }
        
        return false;
    }
    
    bool WorldEngine::buyShip()
    {
    
        if (this->getCurrentPlanet()->getShipyards() > 0)
        {
            if ((this->__player.getNbOre() > CRUISER_COST_MINERALS) &&
                (this->__player.getNbGas() > CRUISER_COST_GAS))
            {
                float   ore = this->__player.getNbOre() - CRUISER_COST_MINERALS;
                float   gas = this->__player.getNbGas() - CRUISER_COST_GAS;
                
                this->__player.setNbGas(gas);
                this->__player.setNbOre(ore);
            
                if (this->getCurrentPlanet()->getFleet() == NULL)
                {
                    this->getCurrentPlanet()->setFleet(new Fleet());
                }
            
                Ship newShip;
                newShip.setArmor(CRUISER_ARMOR);
                newShip.setShield(CRUISER_SHIELD);
                newShip.setStrength(CRUISER_STRENGTH);
            
                this->getCurrentPlanet()->getFleet()->addShip(newShip);
                
                this->updateContext(this->getCurrentPlanet());
                
                return true;
            }
        }
        return false;
    }
}