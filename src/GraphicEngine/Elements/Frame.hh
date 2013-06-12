#ifndef FRAME_HH
#define	FRAME_HH

#include "Component.hh"
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

        private:
            std::list<Component*> __components;
        public:
            std::list<Component*> getComponents() const;
        };

    }
}
#endif	/* FRAME_HH */

