#ifndef MENU_HH
#define	MENU_HH

#include "../GraphicEngine/Elements/Button.hh"
#include "../GraphicEngine/Elements/Frame.hh"
#include <list>

namespace Interface
{
    class Menu : public Graphic::GUI::Frame
    {
    public:
        Menu();
        virtual ~Menu();
        void init();
        
    private:
        Graphic::GUI::Button __startButton;
        Graphic::GUI::Button __optionsButton;
        Graphic::GUI::Button __exitButton;
    public:
        void setExitButton(Graphic::GUI::Button __exitButton);
        Graphic::GUI::Button getExitButton() const;
        void setOptionsButton(Graphic::GUI::Button __optionsButton);
        Graphic::GUI::Button getOptionsButton() const;
        void setStartButton(Graphic::GUI::Button __startButton);
        Graphic::GUI::Button getStartButton() const;
    };

}

#endif	/* MENU_HH */

