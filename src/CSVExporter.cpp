#include "CSVExporter.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <filesystem>

std::string getPBTCsvExportsPath() {
    std::string path = getDocumentsPath() + "PBT_Exports/CSV/";
    std::filesystem::create_directories(path);  // Creates the directory if it doesn't exist
    return path;
}

void CSVExporter::exportToCSV(const std::vector<Transaction>& transactions) {
    std::string path = getPBTCsvExportsPath();
    std::string filename = path + "Transactions_" + getCurrentTimestamp() + ".csv";

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
    std::cout << "Transactions exported to CSV file: " << filename << "\n";
}

