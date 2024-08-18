#include "MainMenu.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
#include "TransactionManager.h"
#include "Utils.h"
#include "xlsxwriter.h"

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
    CSVExporter::exportToCSV(getPBTExportsToCSVPath()+"Transactions_" + getCurrentTimestamp() + ".csv",transactionManager.getTransactions(),"Transactions");
});

    addOption("Export to Excel", [this]() {
        ExcelExporter::exportToExcel( getPBTExportsToExcelPath() + "Transactions_" + getCurrentTimestamp() + ".xlsx", transactionManager.getTransactions(), "Transactions");
    });
    addOption("Data Import", [this]() {
        std::cout << "Importing data...\n";
        transactionManager.importTransactions();
    });

}
