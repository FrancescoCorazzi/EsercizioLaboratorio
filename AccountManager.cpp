//
// Created by coraz on 28/06/19.
//

#include "AccountManager.h"

AccountManager* AccountManager::instance = nullptr;

std::shared_ptr<BankAccount> AccountManager::findAccount(int id) {
    for(auto& a : accounts) {
        if (a->getID() == id) {
            return std::shared_ptr<BankAccount>(a);
        }
    }
    throw accountNotFound();
}

void AccountManager::addAccount() {
    accounts.push_back(std::shared_ptr<BankAccount>(new BankAccount(next_number)));
    updateNextNumber();
}

void AccountManager::addAccount(float balance) {
    accounts.push_back(std::shared_ptr<BankAccount>(new BankAccount(next_number, balance)));
    updateNextNumber();
}

void AccountManager::removeAccount(int id) {
    int i = 0;
    for(auto itr = accounts.begin(); itr != accounts.end(); itr++) {
        if(accounts[i]->getID() == id) {
            if(accounts[i]->getID() < next_number)
                next_number = accounts[i]->getID();
            accounts.erase(itr);
        } else {
            i++;
        }
    }
}

void AccountManager::updateNextNumber() {
    int i = 0;
    bool found;
    do {
        found = false;
        for (auto const& a : accounts) {
            if (a->getID() == i) {
                found = true;
                i++;
                break;
            }
        }
    }
    while(found);
    next_number = i;
}
