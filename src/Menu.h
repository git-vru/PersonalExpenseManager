//
// Created by Vrushabh Jain on 08.07.24.
//

#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <functional>


class Menu {
public:
    Menu(const std::string& title);

    void addOption(const std::string& option, std::function<void()> func);

    void display();

    void run();
    void stop();
private:
    std::vector<std::pair<std::string, std::function<void()>>> options;
    std::string title;
    bool keepRunning;

};



#endif //MENU_H
