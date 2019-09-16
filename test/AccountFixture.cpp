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
        id0 = ac0->getID();
        id1 = ac1->getID();
        id2 = ac2->getID();
        ac0->transferTo(722, ac2);
    }

    AccountManager* am;
    shared_ptr<BankAccount> ac0;
    shared_ptr<BankAccount> ac1;
    shared_ptr<BankAccount> ac2;
    int id0;
    int id1;
    int id2;
};

TEST_F(AccountTesting, SaveToDiskTest) {
    am->saveToFile("../../accounts/");
    am->removeAccount(id0);
    am->removeAccount(id1);
    am->addFromFolder("../../accounts/");
    EXPECT_EQ(am->findAccount(id0)->getBalance(), 5000) << "L'account con ID " + to_string(id0) + " non è stato caricato correttamente";
    EXPECT_EQ(am->findAccount(id2)->getBalance(), 722) << "L'account con ID " + to_string(id2) + " non è stato caricato correttamente";
    EXPECT_EQ(am->findAccount(id1)->getBalance(), am->findAccount(id1)->getBalance())
        << "L'account che aveva ID " + to_string(id1) + " non è stato caricato correttamente";
}