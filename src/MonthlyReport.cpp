#include "MonthlyReport.h"

#include <fstream>
#include <iostream>
#include <xlsxwriter/workbook.h>

#include "TransactionManager.h"
#include "Utils.h"

MonthlyReport::MonthlyReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager), month(0), year(0) {}

void MonthlyReport::generate() {
    std::cout << "Enter month (1-12): ";
    month = getValidatedInputRange(1,12);
    std::cout << "Enter year: ";
    year = getValidatedInputRange(0,2024);

    auto transactions = getTransactions();
    std::cout << "Monthly Report for " << month << "/" << year << ":\n";
    int i=1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(i++) << "\n";
    }
}
std::vector<Transaction> MonthlyReport::getTransactions() const {
    return transactionManager.getTransactionsByMonth(year, month);
}
void MonthlyReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "MonthlyReport_" + std::to_string(month) + "_" + std::to_string(year) + "_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    int row = 0;
    for (const auto& transaction : getTransactions()) {
        worksheet_write_string(worksheet, row, 0, transaction.toString(row + 1).c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << "Monthly Report exported to Excel file: " << filename << "\n";
}
void MonthlyReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "MonthlyReport_" + getCurrentTimestamp() + ".csv";

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
    std::cout << "Monthly Report exported to CSV file: " << filename << "\n";
}


