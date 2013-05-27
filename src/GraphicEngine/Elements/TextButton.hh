#ifndef TEXTBUTTON_HH
#define TEXTBUTTON_HH

#include "Button.hh"
#include <iostream>

class TextButton : public Graphic::Button
{
public:

    TextButton() {
    }

    ~TextButton() {
    }

    void draw();
private:
    std::string __text;
public:
    std::string getText() const;
    void setText(const std::string &text);


};

#endif // TEXTBUTTON_HH
