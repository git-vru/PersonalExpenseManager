#include "MonthlyReport.h"

#include <xlsxwriter/workbook.h>

#include <fstream>
#include <iostream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
#include "TransactionManager.h"
#include "Utils.h"

MonthlyReport::MonthlyReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager), month(0), year(0) {}

void MonthlyReport::generate() {
    std::cout << "Enter month (1-12): ";
    month = getValidatedInputRange(1,12);
    std::cout << "Enter year: ";
    year = getValidatedInputRange(0,2024);

    std::cout << "Monthly Report for " << month << "/" << year << ":\n";
    transactionManager.printTransactions(getTransactions());
}
std::vector<Transaction> MonthlyReport::getTransactions() const {
    return transactionManager.getTransactionsByMonth(year, month);
}
void MonthlyReport::exportToExcel() const {
    std::string filename = getPBTExportsToExcelPath() + "MonthlyReport_" + std::to_string(month) + "_" + std::to_string(year) + "_" + getCurrentTimestamp() + ".xlsx";
    ExcelExporter::exportToExcel(filename,getTransactions(),"Monthly Report");
}
void MonthlyReport::exportToCsv() const {
    std::string filename = getPBTExportsToCSVPath() + "MonthlyReport_" + getCurrentTimestamp() + ".csv";
    CSVExporter::exportToCSV(filename,getTransactions(),"Monthly Report");
}


