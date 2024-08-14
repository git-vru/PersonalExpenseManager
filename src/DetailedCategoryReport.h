//
// Created by Vrushabh Jain on 12.08.24.
//

#ifndef DETAILEDCATEGORYREPORT_H
#define DETAILEDCATEGORYREPORT_H
#include "TransactionManager.h"


class DetailedCategoryReport : public Report{
public:
    explicit DetailedCategoryReport(TransactionManager& transactionManager);
    void generate() override;

    std::vector<Transaction> getTransactions() const;
    std::string getCategoryString() const { return categoryStr; }
    void exportToExcel() const override;
    void exportToCsv() const override;


private:
    TransactionManager& transactionManager;
    Category category;
    std::string categoryStr;


};



#endif //DETAILEDCATEGORYREPORT_H
