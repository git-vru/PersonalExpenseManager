#include "DateRangeReport.h"

#include <xlsxwriter/workbook.h>

#include <fstream>
#include <iostream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
#include "Utils.h"
DateRangeReport::DateRangeReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}

void DateRangeReport::generate() {
    std::cout << "Enter start date (YYYY-MM-DD): ";
    std::cin >> startDate;
    std::cout << "Enter end date (YYYY-MM-DD): ";
    std::cin >> endDate;
    std::cin.ignore();
    std::cout << "Custom Date Range Report (" << startDate << " to " << endDate << "):\n";
    transactionManager.printTransactions(getTransactions());
}
std::vector<Transaction> DateRangeReport::getTransactions() const {
    return transactionManager.getTransactionsByDateRange(startDate, endDate);
}
void DateRangeReport::exportToExcel() const {
    std::string filename = getPBTExportsToExcelPath() + "DateRangeReport_" + getCurrentTimestamp() + ".xlsx";
    ExcelExporter::exportToExcel(filename,getTransactions(),"Custom Date Range Report");
}
void DateRangeReport::exportToCsv() const {
    std::string filename = getPBTExportsToCSVPath() + "DateRangeReport_" + getCurrentTimestamp() + ".csv";
    CSVExporter::exportToCSV(filename,getTransactions(),"Custom Date Range Report");
}

