//
// Created by Vrushabh Jain on 12.08.24.
//

#ifndef DATERANGEREPORT_H
#define DATERANGEREPORT_H
#include "TransactionManager.h"


class DateRangeReport: public Report{
public:
    explicit DateRangeReport(TransactionManager& transactionManager);
    void generate() override;

    std::vector<Transaction> getTransactions() const;
    std::string getStartDate() const { return startDate;}
    std::string getEndDate() const { return endDate;}
    void exportToCsv() const override;
    void exportToExcel() const override;


private:
    TransactionManager& transactionManager;
    std::string startDate, endDate;
};



#endif //DATERANGEREPORT_H
