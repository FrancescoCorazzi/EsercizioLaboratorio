//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_BANKACCOUNT_H
#define ESLABORATORIO_BANKACCOUNT_H


#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
public:

    friend class AccountManager;

    virtual ~BankAccount() { //FIXME handle the vector

    }

    int getID() const { return my_ID; }

    float getBalance() const { return balance; }

    void showTransaction();

    void showTransaction(int i);

    void deposit(float amount);

    bool withdraw(float amount);

    bool transferTo(float amount, int id);

protected: //TODO needed or just private?
    void receiveFrom(float amount, int id);

private:

    explicit BankAccount(int id, float b = 0) : my_ID(id), balance(b) {}

    void transfer(float amount, int id, transaction_type t);

    int my_ID;
    float balance;
    std::vector<Transaction*> transactions;
};


#endif //ESLABORATORIO_BANKACCOUNT_H
