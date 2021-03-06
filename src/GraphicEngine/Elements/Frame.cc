#include "Frame.hh"

namespace Graphic
{
    namespace GUI
    {

        Frame::Frame() {
        }

        Frame::~Frame() {
        }

        void Frame::draw(sf::RenderWindow* window) {
            window->draw(this->__background);
            for (Component* c : this->getComponents()) {
                c->draw(window);
            }
        }
        
        void Frame::update() {
            
        }
        
        void Frame::setBackground(std::string img) {
            std::string file = "ressources/images/" + img;
            if (!this->__backgroundTexture.loadFromFile(file)) {
                std::cerr << "Impossible de charger l'image " << file << std::endl;
                exit(2);
            }
            this->__background.setTexture(this->__backgroundTexture);
        }

        void Frame::addComponent(Component* component) {
            this->__components.push_front(component);
        }

        std::list<Component*> Frame::getComponents() const {
            return __components;
        }
        
        void Frame::setMusic(std::string music)
        {
            this->__music = Musics::getInstance().get(music);
        }
        
        sf::Music* Frame::getMusic()
        {
            return this->__music;
        }
        
    }
}

