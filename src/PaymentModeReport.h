//
// Created by Vrushabh Jain on 12.08.24.
//

#ifndef PAYMENTMODEREPORT_H
#define PAYMENTMODEREPORT_H
#include "TransactionManager.h"


class PaymentModeReport : public Report{
public:
    explicit PaymentModeReport(TransactionManager& transactionManager);
    void generate() override;

    std::vector<Transaction> getTransactions() const;
    std::string getPaymentModeString() const { return paymentModeStr;}
    void exportToExcel() const override;
    void exportToCsv() const override;

private:
    TransactionManager& transactionManager;
    PaymentMode paymentMode;
    std::string paymentModeStr;

};



#endif //PAYMENTMODEREPORT_H
