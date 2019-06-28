//
// Created by coraz on 28/06/19.
//

#include "AccountDatabase.h"


BankAccount *AccountDatabase::findAccount(std::string id) {
    for(auto a : accounts) {
        if (a->getID() == id) {
            return a;
        }
        else {
            return nullptr;
        }
    }
}
