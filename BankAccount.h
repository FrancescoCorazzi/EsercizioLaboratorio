//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_BANKACCOUNT_H
#define ESLABORATORIO_BANKACCOUNT_H


#include <memory>
#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
public:

    friend class AccountManager;

    int getID() const { return my_ID; }

    float getBalance() const { return balance; }

    void showBalance() const;

    void showTransaction() const;

    void showTransaction(int i) const;

    void deposit(float amount);

    bool withdraw(float amount);

    bool transferTo(float amount, int id);

private:
    explicit BankAccount(int id, float b = 0) : my_ID(id), balance(b) {}

    void receiveFrom(float amount, int id);

    void transfer(float amount, int id, transaction_type t);

    int my_ID;
    float balance;
    std::vector<std::unique_ptr<Transaction>> transactions;
};


#endif //ESLABORATORIO_BANKACCOUNT_H
