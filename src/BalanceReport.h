#ifndef BALANCEREPORT_H
#define BALANCEREPORT_H

#include "Report.h"

class BalanceReport : public Report {
public:
    BalanceReport(const std::vector<Transaction>& transactions, double income, double totalExpenses)
        : Report(transactions), income(income), totalExpenses(totalExpenses) {}

    void generate() override;
    double getIncome() const { return income; }
    double getNetBalance() const;
    void exportToCsv() const override;
    void exportToExcel() const override;

private:
    double income;
    double totalExpenses;
};

#endif //BALANCEREPORT_H
