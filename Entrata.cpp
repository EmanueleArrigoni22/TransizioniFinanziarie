//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "Entrata.h"

Entrata::Entrata(const std::string &data, const std::string &descrizione, int importo): Movimento(data,descrizione,importo) {

    this->record = data + ";" + descrizione + ";" + std::to_string(importo);
}
