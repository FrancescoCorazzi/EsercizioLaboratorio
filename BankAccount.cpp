//
// Created by coraz on 28/06/19.
//

#include "BankAccount.h"

void BankAccount::deposit(float amount) {
    transfer(amount, my_ID, DEPOSIT);
    balance += amount;
}

//TODO exceptions?
bool BankAccount::withdraw(float amount) {
    if(balance > amount) {
        transfer(amount * -1, my_ID, WITHDRAWAL);
        balance -= amount;
    }
    else
        return false;
}

bool BankAccount::transferTo(float amount, std::string id) {
    if(balance > amount) {
        transfer(amount * -1, id, OUTGOING);
        balance -= amount;
    }
    else
        return false;
}

void BankAccount::receiveFrom(float amount, std::string id) {
    transfer(amount, id, INGOING);
    balance += amount;
}

void BankAccount::transfer(float amount, std::string id, transaction_type t) {
    auto transaction = new Transaction(t, id, amount, time(nullptr));
    transactions.push_back(transaction);
}
