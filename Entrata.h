//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef ENTRATA_H
#define ENTRATA_H
#include "Movimento.h"


class Entrata : public Movimento{

    public:
    explicit Entrata(const std::string &data, const std::string &descrizione, double importo);
    bool operator==(const Entrata& e) const;
    Entrata(const Entrata& e);
    double effettoSaldo() const override;

};



#endif //ENTRATA_H
