//
// Created by Vrushabh Jain on 11.08.24.
//

#ifndef CATEGORYREPORT_H
#define CATEGORYREPORT_H

#include "Report.h"
#include <map>

class CategoryReport : public Report {
public:
    CategoryReport(const std::vector<Transaction>& transactions, double totalExpenses) : Report(transactions), totalExpenses(totalExpenses) {}

    std::map<Category, double> getCategoryTotals() const;
    void generate() override;
    void exportToCsv() const override;

    double getPercentage(double categoryExpense) const;

    void exportToExcel() const override;
private:
    double totalExpenses;
};



#endif //CATEGORYREPORT_H
