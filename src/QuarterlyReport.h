//
// Created by Vrushabh Jain on 12.08.24.
//

#ifndef QUARTERLYREPORT_H
#define QUARTERLYREPORT_H

#include "TransactionManager.h"

class QuarterlyReport : public Report{
public:
    explicit QuarterlyReport(TransactionManager& transactionManager);
    void generate() override;

    std::vector<Transaction> getTransactions() const;
    int getQuarter() const { return quarter; }
    int getYear() const { return year; }
    void exportToExcel() const override;
    void exportToCsv() const override;



private:
    TransactionManager& transactionManager;
    int quarter, year;
};




#endif //QUARTERLYREPORT_H
