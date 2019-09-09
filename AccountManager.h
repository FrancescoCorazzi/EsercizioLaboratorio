//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_ACCOUNTMANAGER_H
#define ESLABORATORIO_ACCOUNTMANAGER_H


#include <vector>
#include "BankAccount.h"

class AccountManager {
public:

    BankAccount* findAccount(std::string id);

private:
    std::vector<BankAccount*> accounts;
};


#endif //ESLABORATORIO_ACCOUNTMANAGER_H
