#include "ExcelExporter.h"
#include <xlsxwriter.h>
#include "Utils.h"
#include <iostream>
#include <chrono>
#include <string>

void ExcelExporter::exportToExcel(std::string filename, const std::vector<Transaction>& transactions, std::string outro) {

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    worksheet_write_string(worksheet, 0, 0, "Category", NULL);
    worksheet_write_string(worksheet, 0, 1, "Amount", NULL);
    worksheet_write_string(worksheet, 0, 2, "Date", NULL);
    worksheet_write_string(worksheet, 0, 3, "Payment Mode", NULL);
    worksheet_write_string(worksheet, 0, 4, "Message", NULL);

    int row = 1;
    for (const auto& transaction : transactions) {
        worksheet_write_string(worksheet, row, 0, Transaction::getCategoryName(transaction.getCategory()).c_str(), NULL);
        worksheet_write_number(worksheet, row, 1, transaction.getAmount(), NULL);
        worksheet_write_string(worksheet, row, 2, formatDate(transaction.getDate()).c_str(), NULL);
        worksheet_write_string(worksheet, row, 3, Transaction::getPaymentModeName(transaction.getPaymentMode()).c_str(), NULL);
        worksheet_write_string(worksheet, row, 4, transaction.getMessage().c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << outro + " exported to Excel file: " << filename << "\n";
}