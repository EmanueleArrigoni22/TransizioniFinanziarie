//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef ENTRATA_H
#define ENTRATA_H
#include "Movimento.h"


class Entrata : public Movimento{

    public:
    Entrata(const std::string &data, const std::string &descrizione, int importo);
    bool operator==(const Entrata& e) const;
    Entrata(const Entrata& e);
    int effettoSaldo() const override;

};



#endif //ENTRATA_H
