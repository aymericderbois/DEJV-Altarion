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
            std::cout << "Print " << this->getComponents().size() << " elements" << std::endl;
            for (Component* c : this->getComponents()) {
                c->draw(window);
            }
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
    }
}

