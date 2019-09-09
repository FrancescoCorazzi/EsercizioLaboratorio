//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_ACCOUNTMANAGER_H
#define ESLABORATORIO_ACCOUNTMANAGER_H


#include <vector>
#include "BankAccount.h"

class AccountManager {
public:

    static AccountManager* instance;
    static AccountManager* getInstance() {
        if(instance != nullptr)
            return instance;
        else
            return new AccountManager();
    }

    BankAccount* findAccount(int id);

    void addAccount();

    void addAccount(float balance);

    //TODO void addAccount(filestream);

    void removeAccount(int id);

private:
    AccountManager() {
        instance = this;
        next_number = 0;
    }

    void updateNextNumber();

    std::vector<BankAccount*> accounts;
    int next_number;
};

static AccountManager* instance = nullptr;


#endif //ESLABORATORIO_ACCOUNTMANAGER_H
