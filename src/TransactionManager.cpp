#include "TransactionManager.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

#include "CSVImporter.h"
#include "Utils.h"

std::string getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::tm now_tm = *std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d");

    return oss.str();
}

bool isValidDate(const std::string& date_str) {
    std::istringstream iss(date_str);
    int y, m, d;
    char sep1, sep2;
    if ((iss >> y >> sep1 >> m >> sep2 >> d) && (sep1 == '-') && (sep2 == '-')) {
        std::chrono::year year(y);
        std::chrono::month month(m);
        std::chrono::day day(d);
        std::chrono::year_month_day ymd{year, month, day};
        return year.ok() && month.ok() && day.ok() && (ymd == std::chrono::sys_days{ymd});
    }
    return false;
}

void TransactionManager::viewTransactions() const {
    const int numWidth = 5;
    const int categoryWidth = 25;
    const int amountWidth = 10;
    const int dateWidth = 15;
    const int paymentModeWidth = 20;
    const int messageWidth = 30;

    std::cout << std::left << std::setw(numWidth) << "No."
              << std::left << std::setw(categoryWidth) << "Category"
              << std::left << std::setw(amountWidth) << "Amount"
              << std::left << std::setw(dateWidth) << "Date"
              << std::left << std::setw(paymentModeWidth) << "Payment Mode"
              << std::left << std::setw(messageWidth) << "Message" << "\n";
    std::cout << std::string(numWidth + categoryWidth + amountWidth + dateWidth + paymentModeWidth + messageWidth, '-') << "\n";

    int transactionNumber = 1;
    for (const auto& transaction : transactions) {
        std::cout << transaction.toString(transactionNumber);
        transactionNumber++;
    }
}


void TransactionManager::addTransaction() {
    std::string date, message;
    double amount;
    int categoryIndex, paymentModeIndex, choice;

    amount = getValidatedDoubleInput("Enter transaction amount: ");

    std::cout << "Enter transaction date:\n1. Today\n2. Another date\n";
    choice = getValidatedInputRange(1, 2);
    if (choice == 1) {
        date = getCurrentDate();
    } else if (choice == 2) {
        std::cout << "Enter date in the format (YYYY-MM-DD): ";
        std::getline(std::cin, date);
        while (!isValidDate(date)) {
            std::cout << "Invalid date. Enter date in the format (YYYY-MM-DD): ";
            std::getline(std::cin, date);
        }
    }

    std::cout << "Select a payment mode:\n";
    const auto& paymentModenames = Transaction::getAllPaymentModeNames();
    for (size_t i = 0; i < paymentModenames.size(); ++i) {
        std::cout << i + 1 << ". " << paymentModenames[i] << "\n";
    }

    std::cout << "Enter payment mode number: ";
    paymentModeIndex = getValidatedInputRange(1, paymentModenames.size());
    PaymentMode mode = static_cast<PaymentMode>(paymentModeIndex - 1);

    std::cout << "Enter transaction message: ";
    std::getline(std::cin, message);

    std::cout << "Select a category:\n";
    const auto& categoryNames = Transaction::getAllCategoryNames();
    for (size_t i = 0; i < categoryNames.size(); ++i) {
        std::cout << i + 1 << ". " << categoryNames[i] << "\n";
    }

    std::cout << "Enter category number: ";
    categoryIndex = getValidatedInputRange(1, categoryNames.size());
    Category category = static_cast<Category>(categoryIndex - 1);

    transactions.emplace_back(category, amount, date, mode, message);
    std::cout << "Transaction added successfully.\n";
}

void TransactionManager::editTransaction() {
    if (transactions.empty()) {
        std::cout << "No transactions to edit.\n";
        return;
    }

    std::cout << "Select the transaction number to edit:\n";
    viewTransactions();

    std::cout << "Enter transaction number: ";
    int transactionIndex = getValidatedInputRange(1, transactions.size());

    Transaction& transaction = transactions[transactionIndex - 1];

    std::cout << "Editing transaction:\n";
    std::cout << transaction.toString(transactionIndex);

    std::string date, message;
    double amount;
    int categoryIndex, paymentModeIndex, choice;

    amount = getValidatedDoubleInput("Enter new transaction amount (current: "+std::to_string(transaction.getAmount()) +"): ");

    std::cout << "Enter new transaction date:\n1. Keep current date\n2. Change to today\n3. Change to another date\n";
    choice = getValidatedInputRange(1, 3);

    if (choice == 1) {
        date = transaction.getDate();
    } else if (choice == 2) {
        date = getCurrentDate();
    } else if (choice == 3) {
        std::cout << "Enter date in the format (YYYY-MM-DD): ";
        std::getline(std::cin, date);
        while (!isValidDate(date)) {
            std::cout << "Invalid date. Enter date in the format (YYYY-MM-DD): ";
            std::getline(std::cin, date);
        }
    }

    std::cout << "Select a new payment mode (current: " << Transaction::getPaymentModeName(transaction.getPaymentMode()) << "):\n";
    const auto& paymentModenames = Transaction::getAllPaymentModeNames();
    for (size_t i = 0; i < paymentModenames.size(); ++i) {
        std::cout << i + 1 << ". " << paymentModenames[i] << "\n";
    }

    std::cout << "Enter Payment Mode number: ";
    paymentModeIndex = getValidatedInputRange(1, paymentModenames.size());
    PaymentMode mode = static_cast<PaymentMode>(paymentModeIndex - 1);

    std::cout << "Enter new transaction message (current: " << transaction.getMessage() << "): ";
    std::getline(std::cin, message);

    std::cout << "Select a new category (current: " << Transaction::getCategoryName(transaction.getCategory()) << "):\n";
    const auto& categoryNames = Transaction::getAllCategoryNames();
    for (size_t i = 0; i < categoryNames.size(); ++i) {
        std::cout << i + 1 << ". " << categoryNames[i] << "\n";
    }

    std::cout << "Enter category number: ";
    categoryIndex = getValidatedInputRange(1, categoryNames.size());
    Category category = static_cast<Category>(categoryIndex - 1);

    transaction.setCategory(category);
    transaction.setAmount(amount);
    transaction.setDate(date);
    transaction.setPaymentMode(mode);
    transaction.setMessage(message);

    std::cout << "Transaction updated successfully.\n";
}

void TransactionManager::deleteTransaction() {
    if (transactions.empty()) {
        std::cout << "No transactions to delete.\n";
        return;
    }
    viewTransactions();

    std::cout << "Enter transaction number: ";
    int transactionIndex = getValidatedInputRange(1, transactions.size());

    transactions.erase(transactions.begin() + (transactionIndex - 1));
    std::cout << "Transaction deleted successfully.\n";
}

void TransactionManager::importTransactions() {
    std::string filename;
    std::cout << "Enter the CSV filename: ";
    std::getline(std::cin, filename);
    CSVImporter importer(transactions);
    importer.importFromCSV(filename);

}

const std::vector<Transaction>& TransactionManager::getTransactions() const {
    return transactions;
}
std::vector<Transaction> TransactionManager::getTransactionsByMonth(int year, int month) const {
    std::vector<Transaction> result;

    for (const auto& transaction : transactions) {
        auto [transYear, transMonth, transDay] = transaction.getDateComponents();
        if (transYear == year && transMonth == month) {
            result.push_back(transaction);
        }
    }

    return result;
}

std::vector<Transaction> TransactionManager::getTransactionsByQuarter(int year, int quarter) const {
    std::vector<Transaction> result;

    int startMonth = (quarter - 1) * 3 + 1;  // Quarter 1: Jan-March, 2: April-June, etc.
    int endMonth = startMonth + 2;
    for (const auto& transaction : transactions) {
        auto [transYear, transMonth, transDay] = transaction.getDateComponents();
        if (transYear == year && transMonth >= startMonth && transMonth <= endMonth) {
            result.push_back(transaction);
        }
    }
    return result;
}

std::vector<Transaction> TransactionManager::getTransactionsByCategory(Category category) const {
    std::vector<Transaction> result;
    std::copy_if(transactions.begin(), transactions.end(), std::back_inserter(result),
        [category](const Transaction& transaction) {
            return transaction.getCategory() == category;
        });

    return result;
}

std::vector<Transaction> TransactionManager::getTransactionsByDateRange(const std::string& startDate, const std::string& endDate) const {
    std::vector<Transaction> result;

    std::copy_if(transactions.begin(), transactions.end(), std::back_inserter(result),
        [this, &startDate, &endDate](const Transaction& transaction) {
            return isDateInRange(transaction.getDate(), startDate, endDate);
        });

    return result;
}

bool TransactionManager::isDateInRange(const std::string& date, const std::string& startDate, const std::string& endDate) const {
    return date >= startDate && date <= endDate;
}

std::vector<Transaction> TransactionManager::getTransactionsByPaymentMode(PaymentMode paymentMode) const {
    std::vector<Transaction> result;

    std::copy_if(transactions.begin(), transactions.end(), std::back_inserter(result),
        [paymentMode](const Transaction& transaction) {
            return transaction.getPaymentMode() == paymentMode;
        });

    return result;
}

