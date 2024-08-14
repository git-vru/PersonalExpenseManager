#include "DateRangeReport.h"

#include <fstream>
#include <iostream>
#include <xlsxwriter/workbook.h>

#include "Utils.h"
DateRangeReport::DateRangeReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}

void DateRangeReport::generate() {
    std::cout << "Enter start date (YYYY-MM-DD): ";
    std::cin >> startDate;
    std::cout << "Enter end date (YYYY-MM-DD): ";
    std::cin >> endDate;
    std::cin.ignore();

    auto transactions = getTransactions();
    std::cout << "Custom Date Range Report (" << startDate << " to " << endDate << "):\n";
    int i =1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(i++) << "\n";
    }
}
std::vector<Transaction> DateRangeReport::getTransactions() const {
    return transactionManager.getTransactionsByDateRange(startDate, endDate);
}
void DateRangeReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "DateRangeReport_" + startDate + "_to_" + endDate + "_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    int row = 0;
    for (const auto& transaction : getTransactions()) {
        worksheet_write_string(worksheet, row, 0, transaction.toString(row + 1).c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << "Custom Date Range Report exported to Excel file: " << filename << "\n";
}
void DateRangeReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "DateRangeReport_" + getCurrentTimestamp() + ".csv";

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
    std::cout << "Date Range Report exported to CSV file: " << filename << "\n";
}

