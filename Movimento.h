//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include <string>

#include "ContoCorrente.h"


class Movimento {
    public:
        Movimento();
        virtual ~Movimento();
        virtual bool registraMovimento(const ContoCorrente &c);//funzione nella quale si registra sul file il movimento di denaro

};



#endif //MOVIMENTO_H
