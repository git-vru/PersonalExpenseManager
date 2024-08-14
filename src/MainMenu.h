#ifndef MAINMENU_H
#define MAINMENU_H


#include "Menu.h"

#include "TransactionManager.h"
#include "ReportMenu.h"

class MainMenu : public Menu {

public:
    MainMenu(MenuSwitcher& menuSwitcher);


private:
    TransactionManager transactionManager;
    ReportMenu reportMenu;
    MenuSwitcher& menuSwitcher;
};



#endif //MAINMENU_H
