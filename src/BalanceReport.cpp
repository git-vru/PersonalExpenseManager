#include "BalanceReport.h"

#include <fstream>

#include "Utils.h"
#include <xlsxwriter.h>

void BalanceReport::generate()  {

    printHeader("Balance Report");
    std::cout << std::left << std::setw(25) << "Total Income: " << std::right << std::setw(10) << income << "\n";
    std::cout << std::left << std::setw(25) << "Total Expenses: " << std::right << std::setw(10) << totalExpenses << "\n";
    std::cout << std::left << std::setw(25) << "Net Balance: " << std::right << std::setw(10) << getNetBalance() << "\n";
    printFooter();
}

double BalanceReport::getNetBalance() const{
    return income - totalExpenses;
}
void BalanceReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "BalanceReport_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    worksheet_write_string(worksheet, 0, 0, "Balance Report", NULL);

    worksheet_write_string(worksheet, 2, 0, "Total Income", NULL);
    worksheet_write_number(worksheet, 2, 1, getIncome(), NULL);

    worksheet_write_string(worksheet, 3, 0, "Total Expenses", NULL);
    worksheet_write_number(worksheet, 3, 1, totalExpenses, NULL);

    worksheet_write_string(worksheet, 4, 0, "Net Balance", NULL);
    worksheet_write_number(worksheet, 4, 1, totalExpenses, NULL);

    workbook_close(workbook);
    std::cout << "Balance Report exported to Excel file: " << filename << "\n";
}
void BalanceReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "BalanceReport_" + getCurrentTimestamp() + ".csv";

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    double netBalance = getNetBalance();

    file << "Balance Report\n";
    file << "Total Income,Total Expenses,Net Balance\n";

    file << income << "," << totalExpenses << "," << netBalance << "\n";

    file.close();
    std::cout << "Balance Report exported to CSV file: " << filename << "\n";
}

