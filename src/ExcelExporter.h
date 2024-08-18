#ifndef EXCELEXPORTER_H
#define EXCELEXPORTER_H

#include <vector>
#include "Transaction.h"


class ExcelExporter {
public:
     static void exportToExcel(std::string filename, const std::vector<Transaction>& transactions, std::string outro);
};

#endif // EXCELEXPORTER_H
