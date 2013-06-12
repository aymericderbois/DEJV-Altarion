#ifndef GRAPHICENGINE_HH
#define GRAPHICENGINE_HH

#include <SFML/Graphics.hpp>
# include "InterfaceEngine.hh"
#include "../IHM/Menu.hh"

class GraphicEngine
{
public:
    GraphicEngine();
public:
    void setWindow(sf::RenderWindow* window);
    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow* __window;
    InterfaceEngine __interface;
public:
    sf::RenderWindow* GetWindow() const;
    void SetWindow(sf::RenderWindow* __window);
    InterfaceEngine getInterfaceEngine() const;
    void setInterface(InterfaceEngine __interface);

};

#endif // GRAPHICENGINE_HH
