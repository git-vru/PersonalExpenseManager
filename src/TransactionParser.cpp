//
// Created by Vrushabh Jain on 08.08.24.
//

#include "TransactionParser.h"

#include <iostream>

#include "Transaction.h"

Category TransactionParser::parseCategory(const std::string& categoryStr) {
    Category category;
    if (categoryStr == "Groceries") category = Category::Groceries;
    else if (categoryStr == "Transportation") category = Category::Transportation;
    else if (categoryStr == "Housing") category = Category::Housing;
    else if (categoryStr == "Utilities") category = Category::Utilities;
    else if (categoryStr == "Insurance") category = Category::Insurance;
    else if (categoryStr == "EatingOut") category = Category::EatingOut;
    else if (categoryStr == "SavingsAndInvestments") category = Category::SavingsAndInvestments;
    else if (categoryStr == "PersonalSpending") category = Category::PersonalSpending;
    else if (categoryStr == "Entertainment") category = Category::Entertainment;
    else if (categoryStr == "Miscellaneous") category = Category::Miscellaneous;
    else {
        std::cerr << "Unknown category: " << categoryStr << "\n";
        category = Category::Miscellaneous;
    }
    return category;
}

PaymentMode TransactionParser::parsePaymentMode(const std::string& modeStr) {
    PaymentMode paymentMode;
    if (modeStr == "Credit Card") paymentMode = PaymentMode::CreditCard;
    else if (modeStr == "Cash") paymentMode = PaymentMode::Cash;
    else if (modeStr == "Check") paymentMode = PaymentMode::Check;
    else if (modeStr == "Debit Card") paymentMode = PaymentMode::DebitCard;
    else if (modeStr == "Bank Transfer") paymentMode = PaymentMode::BankTransfer;
    else if (modeStr == "Mobile Payment") paymentMode = PaymentMode::MobilePayment;
    else if (modeStr == "Online Payment") paymentMode = PaymentMode::OnlinePayment;
    else if (modeStr == "Other") paymentMode = PaymentMode::Other;
    else {
        std::cerr << "Unknown payment mode: " << modeStr << "\n";
        paymentMode = PaymentMode::Other;
    }
    return paymentMode;
}