//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_ACCOUNTDATABASE_H
#define ESLABORATORIO_ACCOUNTDATABASE_H


#include <vector>
#include "BankAccount.h"

class AccountDatabase {
public:

    BankAccount* findAccount(std::string id);

private:
    std::vector<BankAccount*> accounts;
};


#endif //ESLABORATORIO_ACCOUNTDATABASE_H
