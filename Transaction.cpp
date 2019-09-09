//
// Created by coraz on 28/06/19.
//

#include "Transaction.h"

using namespace std;

void Transaction::showData() const {
    tm* tm = localtime(&date);
    switch(type) {
        case INGOING:
            cout << amount << "€ ricevuti dal conto n. " << other_ID;
            break;
        case OUTGOING:
            cout << amount << "€ inviati al conto n. " << other_ID;
            break;
        case DEPOSIT:
            cout << amount << "€ depositati il";
            break;
        case WITHDRAWAL:
            cout << amount << "€ ritirati il ";
            break;
    }
    cout << " in data " << tm->tm_year + 1900 << "/" << setfill('0') << setw(2) << tm->tm_mon + 1 << "/" <<
         setw(2) << tm->tm_mday << " alle ore " << setw(2) << tm->tm_hour << ":" << setw(2) << tm->tm_min << ":" <<
         setw(2) << tm->tm_sec << endl;
}
