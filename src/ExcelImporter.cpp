// //
// // Created by Vrushabh Jain on 08.08.24.
// //
//
// #include "ExcelImporter.h"
// #include "TransactionParser.h"
// #include <OpenXLSX.hpp> // Include the OpenXLSX library
// #include <iostream>
//
// ExcelImporter::ExcelImporter(std::vector<Transaction>& transactions)
//     : transactions(transactions) {}
//
// void ExcelImporter::importFromExcel(const std::string& filename) {
//     try {
//         OpenXLSX::XLDocument doc;
//         doc.open(filename);
//         auto wks = doc.workbook().worksheet("Sheet1");
//
//         // Start reading from row 2 to skip the header
//         for (unsigned int row = 2; row <= wks.rowCount(); ++row) {
//             std::string categoryStr = wks.cell(row, 1).value().get<std::string>();
//             double amount = wks.cell(row, 2).value().get<double>();
//             std::string date = wks.cell(row, 3).value().get<std::string>();
//             std::string modeStr = wks.cell(row, 4).value().get<std::string>();
//             std::string messageStr = wks.cell(row, 5).value().get<std::string>();
//
//             Category category = TransactionParser::parseCategory(categoryStr);
//             PaymentMode paymentMode = TransactionParser::parsePaymentMode(modeStr);
//
//             transactions.emplace_back(category, amount, date, paymentMode, messageStr);
//         }
//
//         doc.close();
//         std::cout << "Transactions imported successfully from " << filename << ".\n";
//     } catch (const std::exception& e) {
//         std::cerr << "Error importing from Excel: " << e.what() << "\n";
//     }
// }