#ifndef LABEL_HH
#define	LABEL_HH

#include <SFML/Graphics.hpp>
#include "../../Tools/Position.hh"
#include "Component.hh"

namespace Graphic {
    namespace GUI {
        class Label : public Component {
        public:
            Label();
            virtual ~Label();
            void init(int x, int y);
            virtual void draw(sf::RenderWindow* window);
            virtual void update(sf::RenderWindow* window);
            void setText(std::string __text);
            void setFont(std::string fontName);
            void setPosition(Tools::Position __position);
            void setTextSize(int size);
        private:
            sf::Text __text;
            sf::Font __font;
        };
    }
}
#endif	/* LABEL_HH */

