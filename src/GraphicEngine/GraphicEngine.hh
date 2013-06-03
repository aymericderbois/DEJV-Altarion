#ifndef GRAPHICENGINE_HH
#define GRAPHICENGINE_HH

#include <SFML/Graphics.hpp>

class GraphicEngine
{
public:
    GraphicEngine();
    
private:
    sf::RenderWindow* __window;
    
public:
    void setWindow(sf::RenderWindow* window);
    sf::RenderWindow* getWindow();
};

#endif // GRAPHICENGINE_HH
