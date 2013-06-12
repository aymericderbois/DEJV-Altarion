#include "Frame.hh"

namespace Graphic
{
    namespace GUI
    {

        Frame::Frame() {
        }

        Frame::~Frame() {
        }

        void Frame::addComponent(Component* component) {
            this->__components.push_front(component);
        }

        std::list<Component*> Frame::getComponents() const {
            return __components;
        }
    }
}

