//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <list>
#include <string>
#include"Movimento.h"


class ContoCorrente {
    public:

        int saldoCorrente;
        std::string nominativo;
        std::string path;
        std::list<std::unique_ptr<std::string>> operazioni;
        ContoCorrente(std::string nominativo);
        ~ContoCorrente();
        bool registraMovimento(const Movimento &m);

};



#endif //CONTOCORRENTE_H
