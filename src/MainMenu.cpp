#include "MainMenu.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "xlsxwriter.h"
#include "ExcelExporter.h"
#include "CSVExporter.h"
#include "TransactionManager.h"


MainMenu::MainMenu(MenuSwitcher& menuSwitcher)
    : menuSwitcher(menuSwitcher),Menu("Main Menu"),
      reportMenu(menuSwitcher,transactionManager) {
    addOption("Exit", []() {
        std::cout << "Exiting...\n";
        exit(0); // Exit the application
    });

    addOption("View Transactions", [this]() {
        std::cout << "Viewing all transactions...\n";
        transactionManager.viewTransactions();
    });

    addOption("Add Transaction", [this]() {
        transactionManager.addTransaction();
    });

    addOption("Edit Transaction", [this]() {
        transactionManager.editTransaction();
    });

    addOption("Delete Transaction", [this]() {
        transactionManager.deleteTransaction();
    });

    addOption("Generate Reports", [this]() {
        std::cout << "Generating reports...\n";
        reportMenu.run();
    });

    addOption("Export to CSV", [this]() {
    CSVExporter::exportToCSV(transactionManager.getTransactions());
});

    addOption("Export to Excel", [this]() {
        ExcelExporter::exportToExcel(transactionManager.getTransactions());
    });
    addOption("Data Export/Import", [this]() {
        std::cout << "Exporting/importing data...\n";
        transactionManager.importTransactions();
    });

}
