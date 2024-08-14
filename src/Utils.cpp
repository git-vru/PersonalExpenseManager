#include "Utils.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include <filesystem>

std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");
    return ss.str();
}
std::string getPBTExportsToExcelPath() {
    std::string path = getDocumentsPath() + "PBT_Exports/Excel/";
    std::filesystem::create_directories(path);
    return path;
}
std::string getPBTExportsToCSVPath() {
    std::string path = getDocumentsPath() + "PBT_Exports/CSV/";
    std::filesystem::create_directories(path);
    return path;
}

std::string getDocumentsPath() {
    const char* homeDir = getenv("HOME");
    if (homeDir == nullptr) {
        homeDir = getenv("USERPROFILE"); // Windows fallback
    }
    return std::string(homeDir) + "/Documents/";
}
int getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}
int getValidatedInputRange(int min, int max) {
    int input;
    std::string line;
    bool validInput = false;
    while (!validInput) {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> input && !(ss >> line) && input >= min && input <= max) {
            validInput = true;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        }
    }
    return input;
}
double getValidatedDoubleInput(const std::string& prompt) {
    double value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> value && ss.eof() && value >= 0) {  // Ensure it's a valid double and non-negative
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid amount (positive number):\n";
        }
    }
    return value;
}
