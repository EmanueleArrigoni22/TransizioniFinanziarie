//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "Uscita.h"
#include "Movimento.h"

Uscita::Uscita(const std::string &data, const std::string &descrizione, double importo): Movimento(data,descrizione,importo) {

    this->record = data + ";" + descrizione + ";" + "Uscita" + ";" + std::to_string(importo);

}

int Uscita::effettoSaldo() const {
    return (-this->importo);//Nel caso dell'uscita l'effetto sul saldo sarà negativo (il saldo del conto corrente deve diminuire!!)
}
