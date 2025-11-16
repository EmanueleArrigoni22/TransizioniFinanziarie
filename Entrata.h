//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef ENTRATA_H
#define ENTRATA_H
#include "Movimento.h"


class Entrata : public Movimento{

    public:
    Entrata();
    bool operator==(const Entrata& e) const;
    Entrata(const Entrata& e);
    bool registraMovimento(const ContoCorrente &c) override;


};



#endif //ENTRATA_H
