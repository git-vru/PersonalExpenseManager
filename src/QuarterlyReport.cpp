#include "QuarterlyReport.h"

#include <fstream>
#include <iostream>
#include <xlsxwriter/workbook.h>

#include "Utils.h"

QuarterlyReport::QuarterlyReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}
void QuarterlyReport::generate() {
    std::cout << "Enter quarter (1-4): ";
    quarter = getValidatedInputRange(1,4);
    std::cout << "Enter year: ";
    year = getValidatedInputRange(0,2024);

    transactions = getTransactions();
    std::cout << "Quarterly Report for Q" << quarter << " " << year << ":\n";
    int i=1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(i++) << "\n";
    }
}

std::vector<Transaction> QuarterlyReport::getTransactions() const {
    return transactionManager.getTransactionsByQuarter(year, quarter);
}
void QuarterlyReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "QuarterlyReport_Q" + std::to_string(quarter) + "_" + std::to_string(year) + "_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    int row = 0;
    for (const auto& transaction : getTransactions()) {
        worksheet_write_string(worksheet, row, 0, transaction.toString(row + 1).c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << "Quarterly Report exported to Excel file: " << filename << "\n";
}
void QuarterlyReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "QuarterlyReport_" + getCurrentTimestamp() + ".csv";

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
    std::cout << "Quarterly Report exported to CSV file: " << filename << "\n";
}

