#ifndef BUTTON_HH
#define	BUTTON_HH

#include "../../Position.hh"

class Button
{
public:

    void draw() {}

private:
    Position __position;

public:
    void setPosition(Position __position);
    Position getPosition() const;
};

#endif	/* BUTTON_HH */

