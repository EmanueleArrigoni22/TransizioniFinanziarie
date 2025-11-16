//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H
#include <list>
#include <string>


class ContoCorrente {
    public:
        int saldoCorrente;

        std::list<std::unique_ptr<std::string>> operazioni;
        ContoCorrente();
        ~ContoCorrente();

};



#endif //CONTOCORRENTE_H
