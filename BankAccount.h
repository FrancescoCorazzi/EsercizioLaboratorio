//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_BANKACCOUNT_H
#define ESLABORATORIO_BANKACCOUNT_H


//TODO 4 metodi che usano tutti lo stesso metodo
//transferimento soldi (da e a), prelievo e deposito,
//usano tutti Transfer(), che prende in ingresso ID e ammontare e crea la transazione appropriata
//remember to update balance

#include <string>
#include <vector>
#include "Transaction.h"

class BankAccount {
public:
    explicit BankAccount(int id, float b = 0) : my_ID(id), balance(b) {}

    virtual ~BankAccount() { //FIXME handle the vector

    }

    int getID() const { return my_ID; }

    float getBalance() const { return balance; }

    void deposit(float amount);

    bool withdraw(float amount);

    bool transferTo(float amount, int id);

protected: //TODO needed or just private?
    void receiveFrom(float amount, int id);

private:
    void transfer(float amount, int id, transaction_type t);

    const int my_ID;
    float balance;
    std::vector<Transaction*> transactions;
};


#endif //ESLABORATORIO_BANKACCOUNT_H
