#include "PaymentModeReport.h"

#include <fstream>
#include <iostream>
#include <xlsxwriter/workbook.h>

#include "TransactionParser.h"
#include "Utils.h"

PaymentModeReport::PaymentModeReport(TransactionManager& transactionManager)
    : Report(transactionManager.getTransactions()), transactionManager(transactionManager) {}

void PaymentModeReport::generate()  {
    std::cout << "Select a payment mode:\n";
    const auto& paymentModenames = Transaction::getAllPaymentModeNames();
    for (size_t i = 0; i < paymentModenames.size(); ++i) {
        std::cout << i + 1 << ". " << paymentModenames[i] << "\n";
    }

    std::cout << "Enter payment mode number: ";
    int paymentModeIndex = getValidatedInputRange(1, paymentModenames.size())-1;
    paymentMode = static_cast<PaymentMode>(paymentModeIndex);
    paymentModeStr =Transaction::getAllPaymentModeNames().at(paymentModeIndex).c_str();

    auto transactions = getTransactions();
    std::cout << "Report for Payment Mode: " << paymentModeStr << "\n";
    int i=1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(i++) << "\n";
    }
}
std::vector<Transaction> PaymentModeReport::getTransactions() const {
    return transactionManager.getTransactionsByPaymentMode(paymentMode);
}
void PaymentModeReport::exportToExcel() const {
    std::string path = getPBTExportsToExcelPath();
    std::string filename = path + "PaymentModeReport_" + paymentModeStr + "_" + getCurrentTimestamp() + ".xlsx";

    lxw_workbook  *workbook  = workbook_new(filename.c_str());
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    int row = 0;
    for (const auto& transaction : getTransactions()) {
        worksheet_write_string(worksheet, row, 0, transaction.toString(row + 1).c_str(), NULL);
        row++;
    }

    workbook_close(workbook);
    std::cout << "Payment Mode Report for " << paymentModeStr << " exported to Excel file: " << filename << "\n";

}
void PaymentModeReport::exportToCsv() const {
    std::string path = getPBTExportsToCSVPath();
    std::string filename = path + "PaymentModeReport_" + getCurrentTimestamp() + ".csv";

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
    std::cout << "Payment Mode Report exported to CSV file: " << filename << "\n";
}

