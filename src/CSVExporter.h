#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <vector>
#include "Transaction.h"

class CSVExporter {
public:
    static void exportToCSV(std::string filename,const std::vector<Transaction>& transactions,std::string outro);
};

#endif // CSVEXPORTER_H
