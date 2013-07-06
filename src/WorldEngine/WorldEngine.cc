#include "WorldEngine.hh"

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
        srand(time(NULL));
        for (int i = 0; i < nbPlanets; i++) {
            Tools::Position position;
            Planet *planet = new Planet();

            int x = rand() % 708 + 50;
            int y = rand() % 708 + 50;

            while (!choosePosition(x, y, this->__planets)) {
                x = rand() % 708 + 50;
                y = rand() % 708 + 50;
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

        // Création de la topbar
        this->initBar();
        // Adding contextual menu
        this->initContextualHUD();
        this->generateWorld(10);

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
        this->__sidebar.getPanelHeader()->getMinerals()->setValue("30");
        this->__sidebar.getPanelHeader()->getGas()->setValue("30");
    }

    void WorldEngine::setPlayer(Player __player) {
        this->__player = __player;
    }

    Player WorldEngine::getPlayer() const {
        return __player;
    }
}