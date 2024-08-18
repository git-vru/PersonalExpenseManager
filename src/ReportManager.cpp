#include "ReportManager.h"
#include <iostream>

#include "BalanceReport.h"
#include "DateRangeReport.h"
#include "DetailedCategoryReport.h"
#include "ExcelExporter.h"
#include "PaymentModeReport.h"
#include "QuarterlyReport.h"
#include "MonthlyReport.h"
#include "Utils.h"

ReportManager::ReportManager(TransactionManager& transactionManager)
    : transactionManager(transactionManager) {}


void ReportManager::generateBalanceReport() {
    std::cout << "Generating Balance Report...\n";
    BalanceReport report(transactionManager.getTransactions(), getIncome(), getTotalExpenses());
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();
    }
}

void ReportManager::generateCategoryReport() {
    std::cout << "Generating Category-wise Spending Report...\n";
    CategoryReport report(transactionManager.getTransactions(), getTotalExpenses());
    report.generate();
    if(exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}
void ReportManager::generateMonthlyReport() {
    std::cout << "Generating Monthly Report...\n";
    MonthlyReport report(transactionManager);
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}

void ReportManager::generateQuarterlyReport() {
    std::cout << "Generating Quaterly Report...\n";
    QuarterlyReport report(transactionManager);
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}

void ReportManager::generateCategoryWiseDetailedReport() {
    std::cout << "Generating Detailed Category Report...\n";
    DetailedCategoryReport report(transactionManager);
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}

void ReportManager::generateCustomDateRangeReport() {
    std::cout << "Generating Custom Date Range Report...\n";
    DateRangeReport report(transactionManager);
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}

void ReportManager::generateSpecificPaymentModeReport() {
    std::cout << "Generating Specific Payment Mode Report...\n";
    PaymentModeReport report(transactionManager);
    report.generate();
    if (exportToExcel()) {
        report.exportToExcel();
        report.exportToCsv();    }
}
int ReportManager::getIncome() {
    std::cout << "Generating Summary Report...\n";
    int income = getValidatedDoubleInput("Please enter your total income: ");
    return income;
}
bool ReportManager::exportToExcel() {
    std::cout << "Do you want to export the report to excel and csv? (0 = No, 1 = Yes)\n";
    bool choice = getValidatedInputRange(0,1);
    return choice;
}
double ReportManager::getTotalExpenses() {
    double totalExpenses = 0.0;

    for (const auto& transaction : transactionManager.getTransactions()) {
        totalExpenses += transaction.getAmount();
    }
    return  totalExpenses;
}
