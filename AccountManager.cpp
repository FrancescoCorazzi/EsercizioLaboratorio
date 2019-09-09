//
// Created by coraz on 28/06/19.
//

#include "AccountManager.h"


BankAccount *AccountManager::findAccount(std::string id) {
    for(auto a : accounts) {
        if (a->getID() == id) {
            return a;
        }
    }
    return nullptr;
}
