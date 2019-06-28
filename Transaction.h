//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_TRANSACTION_H
#define ESLABORATORIO_TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

typedef unsigned char transaction_type;
const transaction_type INGOING = 0;
const transaction_type OUTGOING = 1;
const transaction_type DEPOSIT = 2;
const transaction_type WITHDRAWAL = 3;

class Transaction {
public:
    //TODO make all private? (with BankAccount friend)
    Transaction(transaction_type t, std::string oid, float a, time_t time) : type(t), other_ID(oid), amount(a), date(time) {}

    transaction_type getType() const { return type; }

    std::string getOtherId() const { return other_ID; }

    float getAmount() const { return amount; }

    time_t getDate() const { return date; }

    void showData() const;

private:
    const transaction_type type;
    const std::string other_ID;
    const float amount;
    const time_t date;
};


#endif //ESLABORATORIO_TRANSACTION_H
