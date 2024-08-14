#ifndef EXCELEXPORTER_H
#define EXCELEXPORTER_H

#include <vector>
#include "Transaction.h"


class ExcelExporter {
public:
     static void exportToExcel(const std::vector<Transaction>& transactions);

};

#endif // EXCELEXPORTER_H
