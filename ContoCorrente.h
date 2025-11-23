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

        double saldoCorrente;
        std::string nominativo;
        std::string path;
        std::list<std::unique_ptr<std::string>> operazioni;
        explicit ContoCorrente(std::string nominativo);
        ~ContoCorrente();
        bool registraMovimento(std::unique_ptr<Movimento>m);
        double getSaldo() const{
            return saldoCorrente;
        }
        std::string getPath() const {
            return path;
        }
};



#endif //CONTOCORRENTE_H
