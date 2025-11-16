//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "Uscita.h"

Uscita::Uscita(const std::string &data, const std::string &descrizione, int importo,const ContoCorrente & c): data(data),descrizione(descrizione), importo(importo) {

    registraMovimento(c);

}

bool Uscita::registraMovimento(const ContoCorrente &c)override{
    bool result = false;



    return result;

}
