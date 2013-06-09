#ifndef GRAPHICENGINE_HH
#define GRAPHICENGINE_HH

#include <SFML/Graphics.hpp>

class GraphicEngine
{
public:
    GraphicEngine();
public:
    void setWindow(sf::RenderWindow* window);
    sf::RenderWindow* getWindow();

private:
    sf::RenderWindow* __window;
public:
    sf::RenderWindow* GetWindow() const;
    void SetWindow(sf::RenderWindow* __window);
};

#endif // GRAPHICENGINE_HH
