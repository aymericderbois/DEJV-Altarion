#ifndef INTERFACE_HH
#define INTERFACE_HH

#include <SFML/Graphics.hpp>
#include <list>
namespace Interface
{
    class Interface
    {
    public:
        Interface() {}
        
        std::list<sf::Drawable*> getDrawables(){
            return list;
        }
        
        void setDrawable(sf::Drawable*  d) {
            list.push_back(d);
        }
        
    private:
        std::list<sf::Drawable*> list;
    };
}

#endif // INTERFACE_HH
