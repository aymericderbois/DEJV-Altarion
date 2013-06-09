#ifndef MENU_HH
#define	MENU_HH

#include "../GraphicEngine/Elements/Button.hh"
#include "../Interface/Interface.hh"

namespace Interface
{
    class Menu : public Interface::Interface
    {
    public:
        Menu();
        virtual ~Menu();
        void init();
        
        virtual std::list<sf::Drawable*> getDrawables();
        
    private:
        Graphic::Button __startButton;
        Graphic::Button __optionsButton;
        Graphic::Button __exitButton;
    public:
        void setExitButton(Graphic::Button __exitButton);
        Graphic::Button getExitButton() const;
        void setOptionsButton(Graphic::Button __optionsButton);
        Graphic::Button getOptionsButton() const;
        void setStartButton(Graphic::Button __startButton);
        Graphic::Button getStartButton() const;
    };

}

#endif	/* MENU_HH */

