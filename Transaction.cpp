//
// Created by coraz on 28/06/19.
//

#include <ctime>
#include "Transaction.h"

void Transaction::showData() const {
    tm* tm = localtime(&date);
    //TODO add more details
    //TODO print different message depending on the other_ID and value (for the 4 types of transactions)
    std::cout << "Transazione eseguita in data " << tm->tm_year + 1900 << "/" << tm->tm_mon + 1 << "/" << tm->tm_mday <<
        " alle ore " << tm->tm_hour << ":" << tm->tm_min << ":" << tm->tm_sec << "." << std::endl;
}
