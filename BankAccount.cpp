//
// Created by coraz on 28/06/19.
//

#include "BankAccount.h"

void BankAccount::deposit(float amount) {
    addTransaction(amount, my_ID, DEPOSIT, time(nullptr));
    balance += amount;
}

void BankAccount::withdraw(float amount) {
    if(balance > amount) {
        addTransaction(amount * -1, my_ID, WITHDRAWAL, time(nullptr));
        balance -= amount;
    }
    else //fondi insufficienti
        throw noMoneyException();
}

void BankAccount::transferTo(float amount, shared_ptr<BankAccount> ba) {
    if(balance > amount) {
        addTransaction(amount * -1, ba->getID(), OUTGOING, time(nullptr));
        balance -= amount;
        ba->receiveFrom(amount, my_ID);
    }
    else //fondi insufficienti
        throw noMoneyException();
}

void BankAccount::receiveFrom(float amount, int id) {
    addTransaction(amount, id, INGOING, time(nullptr));
    balance += amount;
}

void BankAccount::addTransaction(float amount, int oid, transaction_type t, time_t time) {
    transactions.push_back(std::unique_ptr<Transaction>(new Transaction(t, oid, amount, time)));
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
