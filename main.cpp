#include <iostream>
#include "Transaction.h"

//Esercizio 9
//Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita). Le classi devono essere in gradi leggere e salvare i dati su file.


/*
 * Classe conto corrente che contiene lista di transazioni std::vector<Transaction *>, ID del conto<std::string>, e intestatario<std::string>
 * - overload dell'operatore << e >> per leggere/scrivere?
 * - ID assegnato controllando l'esistenza di ID precedenti?
 * - Bilancio totale(long) + bilancio del mese(?)
 *
 * Classe transazione include tipo (enum?), ID dell'altro<std::string>, ammontare<long>, data(unix timestamp?)
 * - istanziabile da dentro un CC (friend?) (CHIEDEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE)
 *
 * Singleton Banca o AccountDatabase con vettore di conti
 * metodo findAccount che restituisce puntatore a account con certo ID
 *
 */


int main() {}
