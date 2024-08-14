//
// Created by Vrushabh Jain on 11.08.24.
//

#include "CategoryReport.h"

#include <fstream>
#include <xlsxwriter/workbook.h>

#include "Utils.h"

std::map<Category, double> CategoryReport::getCategoryTotals() const {
    std::map<Category, double> categoryTotals;
    for (const auto& transaction : transactions) {
        categoryTotals[transaction.getCategory()] += transaction.getAmount();
    }
    return categoryTotals;
}
void CategoryReport::generate()  {
    auto categoryTotals = getCategoryTotals();

    printHeader("Category-wise Spending Report");
    double percentage;
    for (const auto& entry : categoryTotals) {
        percentage = (entry.second / totalExpenses) * 100;
        std::cout << std::left << std::setw(25) << Transaction::getCategoryName(entry.first)
                  << std::left << std::setw(10) << entry.second <<std::fixed
                  << std::left <<std::setprecision(1) << percentage << "%\n";
    }

    printFooter();
}
void CategoryReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "CategoryReport_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    worksheet_write_string(worksheet, 0, 0, "Category", NULL);
    worksheet_write_string(worksheet, 0, 1, "Total Spending", NULL);
    worksheet_write_string(worksheet, 0, 2, "Percentage", NULL);

    int row = 1;
    for (const auto& entry : getCategoryTotals()) {
        worksheet_write_string(worksheet, row, 0, Transaction::getCategoryName(entry.first).c_str(), NULL);
        worksheet_write_number(worksheet, row, 1, entry.second, NULL);
        worksheet_write_number(worksheet, row, 2, getPercentage(entry.second), NULL);

        row++;
    }

    workbook_close(workbook);
    std::cout << "Category-wise Spending Report exported to Excel file: " << filename << "\n";
}

void CategoryReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "CategoryReport_" + getCurrentTimestamp() + ".csv";

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return;
    }

    std::map<Category, double> categoryTotals;
    for (const auto& transaction : transactions) {
        categoryTotals[transaction.getCategory()] += transaction.getAmount();
    }

    file << "Category,Total Amount\n";

    for (const auto& entry : categoryTotals) {
        file << Transaction::getCategoryName(entry.first) << "," << entry.second << "\n";
    }

    file.close();
    std::cout << "Category Report exported to CSV file: " << filename << "\n";
}
double CategoryReport::getPercentage(double categoryExpense) const {
    return (categoryExpense / totalExpenses) * 100;
}