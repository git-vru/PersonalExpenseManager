// //
// // Created by Vrushabh Jain on 08.08.24.
// //
//
 #include "TransactionParser.h"

#include <iostream>
#include <unordered_map>
#include <string>
#include "Transaction.h"
// Mapping from string to Category enum
static const std::unordered_map<std::string, Category> categoryMap = {
    {"Groceries", Category::Groceries},
    {"Transportation", Category::Transportation},
    {"Housing", Category::Housing},
    {"Utilities", Category::Utilities},
    {"Insurance", Category::Insurance},
    {"Eating-Out", Category::EatingOut},
    {"Savings and Investments", Category::SavingsAndInvestments},
    {"Personal Spending", Category::PersonalSpending},
    {"Entertainment", Category::Entertainment},
    {"Miscellaneous", Category::Miscellaneous}
};

// Mapping from string to PaymentMode enum
static const std::unordered_map<std::string, PaymentMode> paymentModeMap = {
    {"Credit Card", PaymentMode::CreditCard},
    {"Cash", PaymentMode::Cash},
    {"Check", PaymentMode::Check},
    {"Debit Card", PaymentMode::DebitCard},
    {"Bank Transfer", PaymentMode::BankTransfer},
    {"Mobile Payment", PaymentMode::MobilePayment},
    {"Online Payment", PaymentMode::OnlinePayment},
    {"Other", PaymentMode::Other}
};
Category TransactionParser::parseCategory(const std::string& categoryStr) {
    auto it = categoryMap.find(categoryStr);
    if (it != categoryMap.end()) {
        return it->second;
    } else {
        std::cerr << "Unknown category: " << categoryStr << "\n";
        return Category::Miscellaneous;
    }
}

PaymentMode TransactionParser::parsePaymentMode(const std::string& modeStr) {
    auto it = paymentModeMap.find(modeStr);
    if (it != paymentModeMap.end()) {
        return it->second;
    } else {
        std::cerr << "Unknown payment mode: " << modeStr << "\n";
        return PaymentMode::Other;
    }
}
