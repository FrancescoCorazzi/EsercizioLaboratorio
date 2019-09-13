//
// Created by coraz on 28/06/19.
//

#include "AccountManager.h"

namespace fs = std::experimental::filesystem;

AccountManager* AccountManager::instance = nullptr;

shared_ptr<BankAccount> AccountManager::findAccount(int id) {
    for(auto& a : accounts) {
        if (a->getID() == id) {
            return shared_ptr<BankAccount>(a);
        }
    }
    throw accountNotFound();
}

shared_ptr<BankAccount> AccountManager::addAccount() {
    accounts.push_back(shared_ptr<BankAccount>(new BankAccount(next_number)));
    updateNextNumber();
    return shared_ptr<BankAccount>(accounts.back());
}

shared_ptr<BankAccount> AccountManager::addAccount(float balance) {
    accounts.push_back(shared_ptr<BankAccount>(new BankAccount(next_number, balance)));
    updateNextNumber();
    return shared_ptr<BankAccount>(accounts.back());
}

void AccountManager::addAccount(ifstream& file, string name) {
    addAccount();
    //verifica se esiste già un conto con l'account, altrimenti modifica l'ID del nuovo conto per essere lo stesso di quello salvato
    try {
        auto a = findAccount(stoi(name));
    }
    catch(accountNotFound& e){
        accounts.back()->my_ID = stoi(name);
    }
    updateNextNumber();
    string line;
    int k = 0;
    //scorre le righe del file per estrarre prima il bilancio, poi le transazioni
    if(file.is_open()){
        while(getline(file, line)){
            if(!k) {
                accounts.back()->balance = stof(line);
                k++;
            } else {
                string delimiter = "::";
                size_t pos = 0;
                int i = 0;
                float bal;
                int oid;
                transaction_type type;
                time_t time;
                string data;
                while ((pos = line.find(delimiter)) != std::string::npos) {
                    data = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());

                    switch (i) {
                        case (0): {
                            bal = stof(data);
                            break;
                        }

                        case (1): {
                            oid = stoi(data);
                            break;
                        }

                        case (2): {
                            type = (transaction_type) stoi(data);
                            break;
                        }

                        case (3): {
                            time = (time_t) stol(data);
                            break;
                        }
                        default:
                            //più di 4 dati nella riga
                            throw runtime_error("La riga conteneva più dati del previsto.");
                    }
                    i++;
                }
                accounts.back()->addTransaction(bal, oid, type, time);
            }
        }
    }
}

void AccountManager::addFromFolder() {
    std::string path = "../accounts/";
    //scorre ogni file della cartella, e passa percorso relativo e nome del file
    for (const auto & entry : fs::directory_iterator(path)) {
        ifstream file(entry.path().string(), ios::in);
        addAccount(file, entry.path().string().substr(path.length()));
    }
}

void AccountManager::removeAccount(int id) {
    int i = 0;
    for(auto itr = accounts.begin(); itr != accounts.end(); itr++) {
        if(accounts[i]->getID() == id) {
            if(accounts[i]->getID() < next_number)
                next_number = accounts[i]->getID();
            accounts.erase(itr);
            break;
        } else {
            i++;
        }
    }
}

void AccountManager::updateNextNumber() {
    // scorre ogni valore a partire da 0 per verificare se esiste già un conto con quell'ID
    int i = 0;
    bool found;
    do {
        found = false;
        for (auto const& a : accounts) {
            if (a->getID() == i) {
                found = true;
                i++;
                break;
            }
        }
    }
    while(found);
    next_number = i;
}

void AccountManager::saveToFile() {
    for(auto const& a : accounts){
        ofstream file("../accounts/" + to_string(a->getID()), ios::trunc | ios::out);
        if(file.is_open()){
            file << to_string(a->getBalance()) + "\n";
            //formatta i membri della transazione come amount::oid::type::date
            for(auto const& t : a->transactions){
                file << to_string(t->getAmount()) + "::" + to_string(t->getOtherId()) + "::" +
                        to_string(t->getType()) + "::" + to_string(t->getDate()) + "\n";
            }
        } else {
            throw runtime_error("Impossibile aprire il file " + to_string(a->getID()));
        }
    }
}
