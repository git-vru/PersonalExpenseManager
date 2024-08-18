//
// Created by Vrushabh Jain on 11.08.24.
//

#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H
#include "TransactionManager.h"

class ReportManager {
public:
    ReportManager(TransactionManager& transactionManager);
    void generateBalanceReport();
    void generateCategoryReport();
    int getIncome();

    void generateMonthlyReport();
    void generateQuarterlyReport();
    void generateCategoryWiseDetailedReport();

    // New custom report methods
    void generateCustomDateRangeReport();
    void generateSpecificPaymentModeReport();
    bool exportToExcel();

    double getTotalExpenses();

   private:
    TransactionManager& transactionManager;
};



#endif //REPORTMANAGER_H
