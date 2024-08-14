//
// Created by Vrushabh Jain on 11.08.24.
//

#ifndef REPORTMENU_H
#define REPORTMENU_H

#include "Menu.h"
#include "MenuSwitcher.h"
#include "ReportManager.h"
#include "TransactionManager.h"

class ReportMenu : public Menu {
public:
    ReportMenu(MenuSwitcher& menuSwitcher,TransactionManager& transactionManager);

private:
    TransactionManager& transactionManager;
    ReportManager reportManager;
    MenuSwitcher& menuSwitcher;

};



#endif //REPORTMENU_H
