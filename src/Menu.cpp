//
// Created by Vrushabh Jain on 08.07.24.
//

#include "Menu.h"

#include <iostream>

#include "Utils.h"
#include<sstream>

Menu::Menu(const std::string& title) : title(title) {}

void Menu::addOption(const std::string& option, std::function<void()> func) {
    options.emplace_back(option, func);
}

void Menu::display() {
    std::cout << "===== " << title << " =====\n";
    int index = 0;
    for (const auto& option : options) {
        std::cout << index << ". " << option.first << "\n";
        index++;
    }
    std::cout << "=============================\n";
    std::cout << "Enter choice: ";
}

void Menu::run() {
    keepRunning = true;
    while (keepRunning) {
        display();
        int choice = getValidatedInputRange(0,options.size()-1);
        // Execute the selected option's function
        options[choice].second();

        //TODO After executing the function, clear screen for better UI
        //system("clear");


        std::cout << "\n";// just a newline to separate menu displays
    }
}
void Menu::stop() {
    keepRunning = false;
}


