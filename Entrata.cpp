//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "Entrata.h"

Entrata::Entrata(const std::string &data, const std::string &descrizione, double importo): Movimento(data,descrizione,importo) {
    if (importo < 0)
        importo = -importo;
    this->record = data + ";" + descrizione + ";" + "Entrata" + ";" + std::to_string(importo);
}

double Entrata::effettoSaldo() const {
    return this->importo;
}
