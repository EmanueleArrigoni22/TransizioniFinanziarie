//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef USCITA_H
#define USCITA_H
#include "Movimento.h"

class Uscita : public Movimento{

public:
        Uscita(const std::string &data, const std::string &descrizione,int importo);
        bool operator==(const Uscita& rhs) const;
        Uscita(const Uscita& u);
        int effettoSaldo() const override;

};



#endif //USCITA_H
