#include "PaymentModeReport.h"

#include <xlsxwriter/workbook.h>

#include <fstream>
#include <iostream>

#include "CSVExporter.h"
#include "ExcelExporter.h"
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

    std::cout << "Report for Payment Mode: " << paymentModeStr << "\n";
    transactionManager.printTransactions(getTransactions());
}
std::vector<Transaction> PaymentModeReport::getTransactions() const {
    return transactionManager.getTransactionsByPaymentMode(paymentMode);
}
void PaymentModeReport::exportToExcel() const {
    std::string filename = getPBTExportsToExcelPath() + "PaymentModeReport_" + paymentModeStr + "_" + getCurrentTimestamp() + ".xlsx";
    ExcelExporter::exportToExcel(filename,getTransactions(),"Payment Mode Report for " + paymentModeStr);

}
void PaymentModeReport::exportToCsv() const {
    std::string filename = getPBTExportsToCSVPath() + "PaymentModeReport_" + getCurrentTimestamp() + ".csv";
    CSVExporter::exportToCSV(filename,getTransactions(),"Payment Mode Report for " + paymentModeStr);
}

