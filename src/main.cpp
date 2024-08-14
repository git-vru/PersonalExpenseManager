#include <iostream>

#include "MainMenu.h"


int main() {
    MenuSwitcher menuSwitcher;

    menuSwitcher.setMenu(std::make_unique<MainMenu>(menuSwitcher));
    menuSwitcher.run();
    return 0;
}
