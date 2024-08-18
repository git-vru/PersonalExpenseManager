#include "CSVExporter.h"
#include "Utils.h"
#include <fstream>
#include <iostream>
#include <filesystem>

void CSVExporter::exportToCSV(std::string filename,const std::vector<Transaction>& transactions,std::string outro) {

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
    std::cout << outro + " exported to CSV file: " << filename << "\n";
}

