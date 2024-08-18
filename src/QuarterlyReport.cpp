#include "QuarterlyReport.h"

#include <fstream>
#include <iostream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
#include "Utils.h"

QuarterlyReport::QuarterlyReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}
void QuarterlyReport::generate() {
    std::cout << "Enter quarter (1-4): ";
    quarter = getValidatedInputRange(1,4);
    std::cout << "Enter year: ";
    year = getValidatedInputRange(0,2024);

    std::cout << "Quarterly Report for Q" << quarter << " " << year << ":\n";
    transactionManager.printTransactions(getTransactions());
}

std::vector<Transaction> QuarterlyReport::getTransactions() const {
    return transactionManager.getTransactionsByQuarter(year, quarter);
}
void QuarterlyReport::exportToExcel() const {
    std::string filename = getPBTExportsToExcelPath() + "QuarterlyReport_Q" + std::to_string(quarter) + "_" + std::to_string(year) + "_" + getCurrentTimestamp() + ".xlsx";
    ExcelExporter::exportToExcel(filename,getTransactions(),"Quarterly report");
}
void QuarterlyReport::exportToCsv() const {
    std::string filename = getPBTExportsToCSVPath() + "QuarterlyReport_" + getCurrentTimestamp() + ".csv";
    CSVExporter::exportToCSV(filename,getTransactions(),"Quarterly report");

}

