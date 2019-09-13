//
// Created by coraz on 13/09/19.
//

#include "gtest/gtest.h"

#include "../AccountManager.h"

class AccountTesting : public ::testing::Test {
protected:
    virtual void SetUp() {
        am = AccountManager::getInstance();
        ac0 = am->addAccount(5722);
        ac1 = am->addAccount(17000);
        ac2 = am->addAccount();
        ac0->transferTo(722, ac2);
    }

    AccountManager* am;
    shared_ptr<BankAccount> ac0;
    shared_ptr<BankAccount> ac1;
    shared_ptr<BankAccount> ac2;
};

TEST_F(AccountTesting, SaveToDiskTest) {
    am->saveToFile();
    am->removeAccount(0);
    am->removeAccount(2);
    am->addFromFolder();
    EXPECT_EQ(am->findAccount(0)->getBalance(), 5000) << "L'account con ID 0 non è stato caricato correttamente";
    EXPECT_EQ(am->findAccount(2)->getBalance(), 722) << "L'account con ID 2 non è stato caricato correttamente";
    EXPECT_EQ(am->findAccount(3)->getBalance(), am->findAccount(1)->getBalance())
        << "L'account che aveva ID 1 non è stato caricato correttamente";
}