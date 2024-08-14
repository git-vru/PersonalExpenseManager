//
// Created by Vrushabh Jain on 11.08.24.
//

#include "Report.h"

void Report::printHeader(const std::string& title) const {
    std::cout << "\n===== " << title << " =====\n";
}

void Report::printFooter() const {
    std::cout << "===============================\n\n";
}