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
    transactions.push_back(std::unique_ptr<Transaction>(new Transaction(t, id, amount, time(nullptr))));
}

void BankAccount::showBalance() const {
    std::cout << std::setprecision(2) << std::fixed << balance << "€" << std::endl;
}

void BankAccount::showTransaction() const {
    int i = 1;
    for(auto& t : transactions) {
        std::cout << i << ". ";
        t->showData();
        i++;
    }
}

void BankAccount::showTransaction(int i) const {
    transactions[i]->showData();
}
