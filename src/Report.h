#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <iostream>
#include <iomanip>
#include "Transaction.h"

class Report {
public:
    Report(const std::vector<Transaction>& transactions) : transactions(transactions) {}
    virtual void generate() = 0; // Pure virtual function without parameters
    virtual ~Report() = default;
    virtual void exportToCsv() const = 0;
    virtual void exportToExcel() const = 0;

protected:
    std::vector<Transaction> transactions;
    void printHeader(const std::string& title) const;
    void printFooter() const;
};

#endif // REPORT_H
