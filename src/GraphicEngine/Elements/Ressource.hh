#ifndef RESSOURCE_HH
#define	RESSOURCE_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Component.hh"
#include "../../Tools/Position.hh"

namespace Graphic {
    namespace GUI {

        class Ressource: public Component
        {
        public:
            Ressource();
            ~Ressource();

            void draw(sf::RenderWindow* window);
            void update(sf::RenderWindow* window);

        private:
            std::string     __value;
            std::string     __icon;
    
            Tools::Position __position;
            Tools::Position __size;

        public:
            void            setValue(std::string text);
            std::string     getValue();
    
            void            setIcon(std::string name);
    
            void            setPosition(Tools::Position __position);
            Tools::Position getPosition() const;
    
            void            setSize(Tools::Position __size);
            Tools::Position getSize() const;
        };
    }
};

#endif	/* RESSOURCE_HH */

