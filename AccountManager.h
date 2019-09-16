//
// Created by coraz on 28/06/19.
//

#ifndef ESLABORATORIO_ACCOUNTMANAGER_H
#define ESLABORATORIO_ACCOUNTMANAGER_H


#include <fstream>
#include <vector>
#include <experimental/filesystem>
#include "BankAccount.h"

using namespace std;

// Singleton

class AccountManager {
public:

    static AccountManager* getInstance() {
        if(instance != nullptr)
            return instance;
        else
            return new AccountManager();
    }

    shared_ptr<BankAccount> findAccount(int id); //trova il puntatore al conto con l'id specificato

    shared_ptr<BankAccount> addAccount(); //aggiunge conto con parametri di default

    shared_ptr<BankAccount> addAccount(float balance); //aggiunge conto con bilancio iniziale

    void addFromFolder(std::string path); //crea un conto per ogni file in ./accounts/

    void saveToFile(std::string path); //salva ogni conto in un file contenente le transazioni

    void removeAccount(int id); //rimuove il conto con l'id specificato

private:

    AccountManager() {
        instance = this;
        next_number = 0;
    }
    void updateNextNumber(); //ricerca l'ID minore disponibile

    void addAccount(ifstream& file, string name); //aggiunge conto a partire da file

    static AccountManager* instance;
    vector<shared_ptr<BankAccount>> accounts;
    int next_number;
};

static AccountManager* instance = nullptr;


#endif //ESLABORATORIO_ACCOUNTMANAGER_H
