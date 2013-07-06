#include "WorldEngine.hh"
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
        std::cout << "draw" << std::endl;
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
        // @fixme Exemple de déplacement de flotte
        Fleet* f = new Fleet();
        f->setMoving(Tools::Position(40, 40), Tools::Position(750, 490));
        this->addFleetInMove(f);
    }

    void WorldEngine::addFleetInMove(Fleet* fleet) {
        this->__fleetInMove.push_back(fleet);
    }

    void WorldEngine::updateContext(Planet *planet) {
        this->__sidebar.getPanelHeader()->setPlanetIcon(planet->getTextureName());
        this->__sidebar.getPanelHeader()->setPlanetName(planet->getName());
        this->__sidebar.getPanelHeader()->getMinerals()->setValue(std::to_string(planet->getMineralsRevenue()));
        this->__sidebar.getPanelHeader()->getGas()->setValue(std::to_string(planet->getGasRevenue()));
    }

    void WorldEngine::setPlayer(Player __player) {
        this->__player = __player;
    }

    Player WorldEngine::getPlayer() const {
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
        this->__player.setNbPlanets(nbShips);
        this->__player.setNbGas(this->__player.getNbGas() + (gasRevenue * 0.0001f));
        this->__player.setNbOre(this->__player.getNbOre() + (oreRevenue * 0.0001f));
        
        this->__topbar.getGas()->setValue(std::to_string((int) floor(this->__player.getNbGas() + 0.5)));
        this->__topbar.getOre()->setValue(std::to_string((int) floor(this->__player.getNbOre() + 0.5)));
        
        this->__topbar.getEarth()->setValue(std::to_string(this->__player.getNbPlanets()));
        this->__topbar.getShips()->setValue(std::to_string(this->__player.getNbShip()));
    }
}