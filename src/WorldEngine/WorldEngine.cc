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
        this->__topbar.setSize(Tools::Position(1024, 40));
        this->__topbar.setPosition(Tools::Position(0, 0));
        this->__topbar.setBackgroundColor(sf::Color(38, 43, 57));
        
        this->addComponent(&this->__topbar);
    }
    
    void    WorldEngine::initContextualHUD()
    {
        this->__sidebar.setSize(Tools::Position(300, 748));
        this->__sidebar.setPosition(Tools::Position(748, 40));
        
        this->__sidebar.setBackgroundColor(sf::Color(38, 43, 57));
        this->__sidebar.setOutlineColor(sf::Color(29, 33, 46));
        
        Graphic::GUI::PanelHeader *planetInfo = new Graphic::GUI::PanelHeader();
        planetInfo->setPlanetIcon("");
        planetInfo->setPlanetName("");
        this->__sidebar.setPanelHeader(&(*planetInfo));
        this->__sidebar.addComponent(&(*planetInfo));
        
        this->addComponent(&this->__sidebar);
    }
      
    void WorldEngine::generateWorld(int nbPlanets) {
        for (int i = 0; i < nbPlanets; i++) {
            Tools::Position position;
            Planet *planet = new Planet();

            int x = rand() % 748 + 40;
            int y = rand() % 748 + 40;

            while (!choosePosition(x, y, this->__planets)) {
                x = rand() % 748 + 40;
                y = rand() % 748 + 40;
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

        // @fixme : generate map here
        this->generateWorld(10);
        //Planet* planet = new Planet();
        //planet->setTexture("Bul");
        //planet->setPosition(Tools::Position(169, 551));
        //planet->setSpriteRatio(0.4);
        //this->__planets.push_back(planet);
        // @endFixme

        for (Planet* planet : this->__planets) {
            planet->setEvent(&this->__action);
            this->addComponent(&(*planet));
        }
    }
    
    void WorldEngine::updateContext(Planet *planet)
    {
        this->__sidebar.getPanelHeader()->setPlanetIcon(planet->getTextureName());
        this->__sidebar.getPanelHeader()->setPlanetName(planet->getName());
    }
}