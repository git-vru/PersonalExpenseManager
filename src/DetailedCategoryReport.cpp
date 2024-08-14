//
// Created by Vrushabh Jain on 12.08.24.
//

#include "DetailedCategoryReport.h"

#include <fstream>

#include "TransactionParser.h"

#include <iostream>
#include <xlsxwriter.h>

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

    auto transactions = getTransactions();
    std::cout << "Detailed Report for Category: " << categoryStr << "\n";
    int i =1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(i++) << "\n";
    }
}

std::vector<Transaction> DetailedCategoryReport::getTransactions() const {
    return transactionManager.getTransactionsByCategory(category);
}
void DetailedCategoryReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "DetailedCategoryReport_" + getCurrentTimestamp() + ".csv";

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    file << "Category,Amount,Date,Payment Mode,Message\n";

    for (const auto& transaction : transactions) {
        file << Transaction::getCategoryName(transaction.getCategory()) << ","
             << transaction.getAmount() << ","
             << transaction.getDate() << ","
             << Transaction::getPaymentModeName(transaction.getPaymentMode()) << ","
             << transaction.getMessage() << "\n";
    }

    file.close();
    std::cout << "Detailed Category Report exported to CSV file: " << filename << "\n";
}
void DetailedCategoryReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "DetailedCategoryReport_" + categoryStr + "_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    int row = 0;
    for (const auto& transaction : getTransactions()) {
        worksheet_write_string(worksheet, row, 0, transaction.toString(row + 1).c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << "Detailed Category Report for " << categoryStr << " exported to Excel file: " << filename << "\n";
}


