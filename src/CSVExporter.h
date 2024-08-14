#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <vector>
#include "Transaction.h"

class CSVExporter {
public:
    static void exportToCSV(const std::vector<Transaction>& transactions);

    void exportToCSV() const;
};

#endif // CSVEXPORTER_H
