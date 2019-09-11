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
        return true;
    }
    else
        return false;
}

bool BankAccount::transferTo(float amount, int id) {
    if(balance > amount) {
        transfer(amount * -1, id, OUTGOING);
        balance -= amount;
        //TODO call receiveFrom()
        return true;
    }
    else
        return false;
}

void BankAccount::receiveFrom(float amount, int id) {
    transfer(amount, id, INGOING);
    balance += amount;
}

void BankAccount::transfer(float amount, int id, transaction_type t) {
    auto transaction = new Transaction(t, id, amount, time(nullptr));
    transactions.push_back(transaction);
}

void BankAccount::showTransaction() {
    int i = 0;
    for(auto t : transactions) {
        std::cout << i << ". ";
        t->showData();
        i++;
    }
}

void BankAccount::showTransaction(int i) {
    transactions[i]->showData();
}
