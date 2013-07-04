#ifndef MENU_HH
#define	MENU_HH

#include <list>

#include "../GraphicEngine/Elements/Button.hh"
#include "../GraphicEngine/Elements/Frame.hh"

#include "../ActionEngine/MenuAction.hh"

namespace Interface
{
    class Menu : public Graphic::GUI::Frame
    {
    public:
        Menu();
        virtual ~Menu();
        void init();
        void buttonOnHover(Graphic::GUI::Button* button);
    private:
        Graphic::GUI::Button __startButton;
        Graphic::GUI::Button __optionsButton;
        Graphic::GUI::Button __exitButton;
        MenuAction __action;
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

