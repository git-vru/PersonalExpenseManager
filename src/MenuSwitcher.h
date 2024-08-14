//
// Created by Vrushabh Jain on 11.08.24.
//

#ifndef MENUSWITCHER_H
#define MENUSWITCHER_H

#include "Menu.h"
#include <stack>

class MenuSwitcher {
public:
    void setMenu(std::unique_ptr<Menu> menu);
    void run();

private:
    std::unique_ptr<Menu> currentMenu;
    std::stack<std::unique_ptr<Menu>> menuHistory;
};



#endif //MENUSWITCHER_H
