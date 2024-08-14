
#include "ReportMenu.h"
#include "MainMenu.h"
#include "Utils.h"


ReportMenu::ReportMenu(MenuSwitcher& menuSwitcher,TransactionManager& transactionManager)
    : menuSwitcher(menuSwitcher), Menu("Generate Reports"), transactionManager(transactionManager), reportManager(transactionManager) {
    addOption("Back to Main Menu", [&,this]() {
        std::cout << "Returning to Main Menu...\n";
        menuSwitcher.setMenu(std::make_unique<MainMenu>(menuSwitcher));
        stop();
    });

    addOption("Balance Report", [this]() { reportManager.generateBalanceReport(); });
    addOption("Category-wise Spending Report", [this]() { reportManager.generateCategoryReport(); });
    addOption("Monthly Report", [this]() { reportManager.generateMonthlyReport(); });
    addOption("Quarterly Report", [this]() { reportManager.generateQuarterlyReport(); });
    addOption("Category-wise Detailed Report", [this]() { reportManager.generateCategoryWiseDetailedReport(); });
    addOption("Custom Date Range Report", [this]() { reportManager.generateCustomDateRangeReport(); });
    addOption("Specific Payment Mode Report", [this]() { reportManager.generateSpecificPaymentModeReport(); });

}

