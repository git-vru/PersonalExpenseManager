//
// Created by Vrushabh Jain on 11.08.24.
//

#include "MenuSwitcher.h"

void MenuSwitcher::setMenu(std::unique_ptr<Menu> menu) {
    if (currentMenu) {
        menuHistory.push(std::move(currentMenu));
    }
    currentMenu = std::move(menu);
}

void MenuSwitcher::run() {
    while (currentMenu) {
        currentMenu->run();
        currentMenu = nullptr; // Ensure we clear the current menu after running
        if (!menuHistory.empty()) {
            currentMenu = std::move(menuHistory.top());
            menuHistory.pop();
        }
    }
}