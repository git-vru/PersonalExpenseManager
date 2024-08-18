//
// Created by Vrushabh Jain on 12.08.24.
//

#include "DetailedCategoryReport.h"

#include <xlsxwriter.h>

#include <fstream>
#include <iostream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
#include "TransactionParser.h"
#include "Utils.h"
DetailedCategoryReport::DetailedCategoryReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}

void DetailedCategoryReport::generate() {

    std::cout << "Select a category:\n";
    const auto& categoryNames = Transaction::getAllCategoryNames();
    for (int i = 0; i < Transaction::getAllCategoryNames().size(); i++) {
        std::cout << i+1 << ". " << categoryNames[i] << "\n";
    }

    std::cout << "Enter category number: ";
    int categoryIndex = getValidatedInputRange(1, categoryNames.size())-1;
    category = static_cast<Category>(categoryIndex);

    categoryStr =Transaction::getAllCategoryNames().at(categoryIndex).c_str();

    std::cout << "Detailed Report for Category: " << categoryStr << "\n";
    transactionManager.printTransactions(getTransactions());
}

std::vector<Transaction> DetailedCategoryReport::getTransactions() const {
    return transactionManager.getTransactionsByCategory(category);
}
void DetailedCategoryReport::exportToCsv() const {
    std::string filename = getPBTExportsToCSVPath() + "DetailedCategoryReport_" + getCurrentTimestamp() + ".csv";
    CSVExporter::exportToCSV(filename,getTransactions(), "Detailed Category Report for " + categoryStr);
}
void DetailedCategoryReport::exportToExcel() const {
    std::string filename = getPBTExportsToExcelPath() + "DetailedCategoryReport_" + categoryStr + "_" + getCurrentTimestamp() + ".xlsx";
    ExcelExporter::exportToExcel(filename,getTransactions(), "Detailed Category Report for " + categoryStr);
}


