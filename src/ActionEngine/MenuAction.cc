/* 
 * File:   MenuAction.cc
 * Author: Aymeric
 * 
 * Created on 2 juillet 2013, 14:29
 */

#include "MenuAction.hh"

MenuAction::MenuAction() {
}

MenuAction::~MenuAction() {
}

void MenuAction::eventPerform(EventLauncher *launcher, int identifier)
{
    std::cout << "Action Performed" << std::endl;
}
