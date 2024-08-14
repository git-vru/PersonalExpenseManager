//
// Created by Vrushabh Jain on 08.08.24.
//

#ifndef EXCELIMPORTER_H
#define EXCELIMPORTER_H
#include <vector>
#include <string>
#include "Transaction.h"


class ExcelImporter {
public:
    explicit ExcelImporter(std::vector<Transaction>& transactions);
    void importFromExcel(const std::string& filename);

private:
    std::vector<Transaction>& transactions;
};



#endif //EXCELIMPORTER_H
