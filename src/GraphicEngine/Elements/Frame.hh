#ifndef FRAME_HH
#define	FRAME_HH

#include "Component.hh"
#include "../../Tools/Music.hh"
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>

namespace Graphic
{
    namespace GUI
    {

        class Frame
        {
        public:
            Frame();
            virtual ~Frame();
            void addComponent(Component* component);
            void setBackground(std::string img);
            virtual void draw(sf::RenderWindow* window);
            virtual void update();
            void setMusic(std::string music);
            sf::Music* getMusic();
        private:
            std::list<Component*> __components;
            sf::Sprite __background;
            sf::Texture __backgroundTexture;
            sf::Music*   __music;
        public:
            std::list<Component*> getComponents() const;
        };

    }
}
#endif	/* FRAME_HH */

