//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef USCITA_H
#define USCITA_H
#include "Movimento.h"
#include "ContoCorrente.h"


class Uscita : public Movimento{

    public:
        int importo;
        std::string data;
        std::string descrizione;
        Uscita() = default;
        Uscita(const std::string &data, const std::string &descrizione, int importo,const ContoCorrente &c);
        bool registraMovimento(const ContoCorrente &c) override;
        bool operator==(const Uscita& rhs) const;
        Uscita(const Uscita& u);
};



#endif //USCITA_H
