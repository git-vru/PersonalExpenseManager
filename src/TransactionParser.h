//
// Created by Vrushabh Jain on 08.08.24.
//

#ifndef TRANSACTIONPARSER_H
#define TRANSACTIONPARSER_H


#include "Transaction.h"


class TransactionParser {
public:
    static Category parseCategory(const std::string& categoryStr);
    static PaymentMode parsePaymentMode(const std::string& modeStr);
};



#endif //TRANSACTIONPARSER_H
