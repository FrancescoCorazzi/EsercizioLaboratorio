//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_BANKACCOUNT_H
#define ESLABORATORIO_BANKACCOUNT_H


#include <memory>
#include <string>
#include <vector>
#include "Exceptions.h"
#include "Transaction.h"

class BankAccount {
public:

    friend class AccountManager;  //uso del costruttore privato

    int getID() const { return my_ID; }

    float getBalance() const { return balance; }

    void showBalance() const; //print

    void showTransaction() const; //print le transazioni

    void showTransaction(int i) const; //print la transazione numero i

    void deposit(float amount); //aggiunge soldi al conto

    void withdraw(float amount); //preleva soldi dal conto

    void transferTo(float amount, shared_ptr<BankAccount> ba); //trasferisce soldi a un altro conto

private:
    explicit BankAccount(int id, float b = 0) : my_ID(id), balance(b) {}

    void receiveFrom(float amount, int id); //riceve soldi da un altro conto

    void transfer(float amount, int id, transaction_type t); //crea l'oggetto Transaction

    void addTransaction(float amount, int oid, transaction_type t, time_t time); //crea un oggetto Transaction usato nella lettura da file

    int my_ID;
    float balance;
    std::vector<std::unique_ptr<Transaction>> transactions;
};


#endif //ESLABORATORIO_BANKACCOUNT_H
