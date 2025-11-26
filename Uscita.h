//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef USCITA_H
#define USCITA_H
#include "Movimento.h"

class Uscita : public Movimento{

public:
       explicit Uscita(const std::string &data, const std::string &descrizione,double importo);
        bool operator==(const Uscita& rhs) const;
        Uscita(const Uscita& u);
        double effettoSaldo() const override;

};



#endif //USCITA_H
