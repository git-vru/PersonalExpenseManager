//
// Created by Vrushabh Jain on 08.08.24.
//

#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H


#include "Transaction.h"
#include "CategoryReport.h"

class TransactionManager {
public:
    void viewTransactions() const;
    void addTransaction();
    void editTransaction();
    void deleteTransaction();
    void importTransactions();
    const std::vector<Transaction>& getTransactions() const;

    std::vector<Transaction> getTransactionsByMonth(int year, int month) const;
    std::vector<Transaction> getTransactionsByQuarter(int year, int quarter) const;
    std::vector<Transaction> getTransactionsByCategory(Category category) const;
    std::vector<Transaction> getTransactionsByDateRange(
        const std::string& startDate, const std::string& endDate) const;
    std::vector<Transaction> getTransactionsByPaymentMode(
        PaymentMode paymentMode) const;
    void printTransactions(std::vector<Transaction> transactions) const;

   private:
    std::vector<Transaction> transactions;

};



#endif //TRANSACTIONMANAGER_H
