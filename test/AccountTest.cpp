//
// Created by coraz on 13/09/19.
//

#include "gtest/gtest.h"

#include "../AccountManager.h"

TEST(BankAccount, AccountCreation) {
    auto am = AccountManager::getInstance();
    auto ac0 = am->addAccount();
    ASSERT_EQ(ac0->getBalance(), 0) << "Il bilancio ha il valore sbagliato";
    ASSERT_EQ(ac0->getID(), 0) << "L'ID è errato";
    auto ac1 = am->addAccount(1000);
    ASSERT_EQ(am->findAccount(1)->getBalance(), 1000) << "Il bilancio ha il valore sbagliato";
}

TEST(BankAccount, TestDeposit) {
    auto am = AccountManager::getInstance();
    auto ac = am->addAccount();
    ac->deposit(50);
    ASSERT_EQ(ac->getBalance(), 50) << "I soldi non sono stati depositati";
}

TEST(BankAccount, TestWithdrawal) {
    auto am = AccountManager::getInstance();
    auto ac = am->addAccount(100);
    ac->withdraw(50);
    ASSERT_EQ(ac->getBalance(), 50) << "I soldi non sono stati prelevati";
}

TEST(BankAccount, TestTransfer) {
    auto am = AccountManager::getInstance();
    auto ac0 = am->addAccount(1000);
    auto ac1 = am->addAccount(500);
    ac0->transferTo(250, ac1);
    ASSERT_EQ(ac0->getBalance(), 750) << "Il primo account non ha spedito i soldi";
    ASSERT_EQ(ac1->getBalance(), 750)  << "Il secondo account non ha ricevuto i soldi";
}

TEST(BankAccount, NextIDTest) {
    auto am = AccountManager::getInstance();
    auto ac0 = am->addAccount();
    auto ac1 = am->addAccount();
    auto ac2 = am->addAccount();
    am->removeAccount(1);
    auto ac3 = am->addAccount();
    ASSERT_EQ(ac3->getID(), 1) << "L'ID non è aggiornato correttamente";
}
