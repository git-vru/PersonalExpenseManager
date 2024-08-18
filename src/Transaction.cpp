//
// Created by Vrushabh Jain on 09.07.24.
//

#include "Transaction.h"
#include <sstream>
#include <iomanip>
#include <tuple>
#include <chrono>

Transaction::Transaction(Category category, double amount, const std::chrono::year_month_day& date,PaymentMode paymentMode, const std::string& message)
    : category(category), amount(amount), date(date),paymentMode(paymentMode), message(message) {}

Category Transaction::getCategory() const { return category; }
double Transaction::getAmount() const { return amount; }
std::chrono::year_month_day Transaction::getDate() const { return date; }
std::string Transaction::getMessage() const { return message; }
PaymentMode Transaction::getPaymentMode() const { return paymentMode; }

void Transaction::setCategory(Category newCategory) { category = newCategory; }
void Transaction::setAmount(double newAmount) { amount = newAmount; }
void Transaction::setDate(const std::chrono::year_month_day& newDate) { date = newDate; }
void Transaction::setMessage(const std::string& newMessage) { message = newMessage; }
void Transaction::setPaymentMode(PaymentMode newPaymentMode) {
    paymentMode = newPaymentMode;
}

std::string Transaction::toString(int transactionNumber) const {
    const int numWidth = 5;
    const int categoryWidth = 25;
    const int amountWidth = 10;
    const int dateWidth = 15;
    const int paymentModeWidth = 20;
    const int messageWidth = 30;

    std::ostringstream oss;
    oss << std::left << std::setw(numWidth) << transactionNumber
        << std::left << std::setw(categoryWidth) << getCategoryName(category)
        << std::left << std::setw(amountWidth) << amount
        << std::left << std::setw(dateWidth) << date
        << std::left << std::setw(paymentModeWidth) << getPaymentModeName(paymentMode)
        << std::left << std::setw(messageWidth) << " " + message << "\n";

    return oss.str();
}


std::string Transaction::getCategoryName(Category category) {
    switch (category) {
        case Category::Groceries: return "Groceries";
        case Category::Transportation: return "Transportation";
        case Category::Housing: return "Housing";
        case Category::Utilities: return "Utilities";
        case Category::Insurance: return "Insurance";
        case Category::EatingOut: return "Eating-Out";
        case Category::SavingsAndInvestments: return "Savings and Investments";
        case Category::PersonalSpending: return "Personal Spending";
        case Category::Entertainment: return "Entertainment";
        case Category::Miscellaneous: return "Miscellaneous";
        default: return "Unknown";
    }
}
const std::vector<std::string>& Transaction::getAllCategoryNames() {
    static const std::vector<std::string> categoryNames = {
        "Groceries",
        "Transportation",
        "Housing",
        "Utilities",
        "Insurance",
        "Eating Out",
        "Savings and Investments",
        "Personal Spending",
        "Entertainment",
        "Miscellaneous"
    };
    return categoryNames;
}
std::string Transaction::getPaymentModeName(PaymentMode mode) {
    switch (mode) {
        case PaymentMode::CreditCard: return "Credit Card";
        case PaymentMode::Cash: return "Cash";
        case PaymentMode::DebitCard: return "Debit Card";
        case PaymentMode::BankTransfer: return "Bank Transfer";
        case PaymentMode::MobilePayment: return "Mobile Payment";
        case PaymentMode::Check: return "Check";
        case PaymentMode::OnlinePayment: return "Online Payment";
        case PaymentMode::Other: return "Other";
        default: return "Unknown";
    }
}
const std::vector<std::string>& Transaction::getAllPaymentModeNames() {
    static const std::vector<std::string> paymentModeNames = {
        "Credit Card",
        "Cash",
        "Debit Card",
        "Bank Transfer",
        "Mobile Payment",
        "Check",
        "Online Payment",
        "Other"
    };
    return paymentModeNames;
}



