// //
// // Created by Vrushabh Jain on 08.08.24.
// //
//
// #include "CSVImporter.h"
// #include <fstream>
// #include <sstream>
// #include <iostream>
// #include "TransactionParser.h"
//
// CSVImporter::CSVImporter(std::vector<Transaction>& transactions)
//     : transactions(transactions) {}
//
// void CSVImporter::importFromCSV(const std::string& filename) {
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "\nError opening file: " << filename << "\n";
//         return;
//     }
//
//     std::string line;
//     std::getline(file, line); // Skip header line
//
//     while (std::getline(file, line)) {
//         std::istringstream stream(line);
//         std::string categoryStr, amountStr, date, modeStr, messageStr;
//         std::getline(stream, categoryStr, ',');
//         std::getline(stream, amountStr, ',');
//         std::getline(stream, date, ',');
//         std::getline(stream, modeStr, ',');
//         std::getline(stream, messageStr);
//
//         Category category = TransactionParser::parseCategory(categoryStr);
//         PaymentMode paymentMode = TransactionParser::parsePaymentMode(modeStr);
//         double amount = std::stod(amountStr);
//
//         transactions.emplace_back(category, amount, date, paymentMode, messageStr);
//     }
//
//     std::cout << "Transactions imported successfully from " << filename << ".\n";
// }
#include "CSVImporter.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "TransactionParser.h"
#include "Utils.h"

CSVImporter::CSVImporter(std::vector<Transaction>& transactions)
    : transactions(transactions) {}

void CSVImporter::importFromCSV(const std::string& initialFilename) {
    std::string filename = initialFilename;
    std::ifstream file;

    while (true) {
        // Check if the file has a .csv extension
        if (filename.length() < 4 || filename.substr(filename.length() - 4) != ".csv") {
            std::cerr << "Error: The file must be a .csv file. Please enter a valid CSV file path: ";
            std::getline(std::cin, filename);
            continue;
        }

        file.open(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << "\n";
            std::cout << "Please enter a valid file path: ";
            std::getline(std::cin, filename);
        } else {
            break; // Exit the loop if the file is successfully opened
        }
    }

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string categoryStr, amountStr, dateStr, modeStr, messageStr;
        std::getline(stream, categoryStr, ',');
        std::getline(stream, amountStr, ',');
        std::getline(stream, dateStr, ',');
        std::getline(stream, modeStr, ',');
        std::getline(stream, messageStr);

        try {
            Category category = TransactionParser::parseCategory(categoryStr);
            PaymentMode paymentMode = TransactionParser::parsePaymentMode(modeStr);
            double amount = std::stod(amountStr);
            std::chrono::year_month_day date = parseDate(dateStr);

            transactions.emplace_back(category, amount, date, paymentMode, messageStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error parsing line: " << line << "\n";
        }
    }

    std::cout << "Transactions imported successfully from " << filename << ".\n";
}
