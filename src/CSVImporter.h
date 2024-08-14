//
// Created by Vrushabh Jain on 08.08.24.
//

#ifndef CSVIMPORTER_H
#define CSVIMPORTER_H

#include <string>
#include <vector>
#include "Transaction.h"

class CSVImporter {
public:

    CSVImporter(std::vector<Transaction>& transactions);

    void importFromCSV(const std::string& filename);

private:
    std::vector<Transaction>& transactions;


};

#endif //CSVIMPORTER_H
