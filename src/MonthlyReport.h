//
// Created by Vrushabh Jain on 12.08.24.
//

#ifndef MONTHLYREPORT_H
#define MONTHLYREPORT_H

#include "TransactionManager.h"

class MonthlyReport:public Report{
public:
    explicit MonthlyReport(TransactionManager& transactionManager);
    void generate() override;

    std::vector<Transaction> getTransactions() const;
    int getMonth() const { return month; }
    int getYear() const { return year; }
    void exportToExcel() const override;
    void exportToCsv() const override;


private:
    TransactionManager& transactionManager;
    int month, year;
};


#endif //MONTHLYREPORT_H
