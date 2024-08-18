//
// Created by Vrushabh Jain on 09.07.24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <tuple>
#include <chrono>

enum class Category {
    Groceries,
    Transportation,
    Housing,
    Utilities,
    Insurance,
    EatingOut,
    SavingsAndInvestments,
    PersonalSpending,
    Entertainment,
    Miscellaneous
};

enum class PaymentMode {
    CreditCard,
    Cash,
    DebitCard,
    BankTransfer,
    MobilePayment,
    Check,
    OnlinePayment,
    Other
};

class Transaction {
public:
    Transaction(Category category, double amount, const std::chrono::year_month_day& date, PaymentMode paymentMode, const std::string& message = "");

    // Getters
    Category getCategory() const;
    double getAmount() const;
    std::chrono::year_month_day getDate() const;
    std::string getMessage() const;
    PaymentMode getPaymentMode() const;
    // Setters
    void setCategory(Category newCategory);
    void setAmount(double newAmount);
    void setDate(const std::chrono::year_month_day& newDate);
    void setMessage(const std::string& newMessage);
    void setPaymentMode(PaymentMode newPaymentMode);

    std::string toString(int transactionNumber) const;
    static std::string getCategoryName(Category category);
    static const std::vector<std::string>& getAllCategoryNames();
    static std::string getPaymentModeName(PaymentMode payment_mode);
    static const std::vector<std::string>& getAllPaymentModeNames();
    std::tuple<int, int, int> getDateComponents() const;
    std::string formatDate(const std::chrono::year_month_day& date) const;


private:
    Category category;
    double amount;
    std::chrono::year_month_day date;
    std::string message;
    PaymentMode paymentMode;
};



#endif //TRANSACTION_H
