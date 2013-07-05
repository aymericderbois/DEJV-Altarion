#include "WorldEngine.hh"
namespace World
{
    WorldEngine::WorldEngine()
    {
        generateWorld(10);
    }
    
    WorldEngine::~WorldEngine()
    {
        while (!this->__planets.empty())
        {
            this->__planets.pop_front();
        }
    }
    
    
    bool    choosePosition(int                  x,
                           int                  y,
                           std::list<Planet*>   planets)
    {
        int padding     = 30;
        
        for (Planet* planet : planets)
        {
            if (((planet->GetPosition().getX() < x + padding) && (planet->GetPosition().getX() < x - padding)) &&
                ((planet->GetPosition().getY() < y + padding) && (planet->GetPosition().getY() < y - padding)))
                return false;
        }
        return true;
    }
    
    void    WorldEngine::generateWorld(int  nbPlanets)
    {
        for (int i = 0; i < nbPlanets; i++)
        {
            Tools::Position position;
            Planet *planet = new Planet();
            
            int x = rand() % 674 + 20;
            int y = rand() % 674 + 20;
            
            while (!choosePosition(x, y, this->__planets))
            {
                x = rand() % 674 + 20;
                y = rand() % 674 + 20;
            }
            
            position.setX(x);
            position.setY(y);
            
            planet->SetPosition(position);
            
            this->__planets.push_front(planet);
            
            std::cout << "Added planet:" << planet->getName() << " x:" << planet->GetPosition().getX() << " y: " << planet->GetPosition().getY() << std::endl;
        }
    }
}