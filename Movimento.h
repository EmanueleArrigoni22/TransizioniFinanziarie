//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include <string>


class Movimento {
public:
    Movimento(const std::string &data, const std::string &descrizione, int importo);
    virtual ~Movimento() = 0;
    std::string getData() const {
        return data;
    }
    std::string getDescrizione() const {
        return descrizione;
    }
    int getImporto() const {
        return importo;
    }
    std::string getRecord() const {
        return record;
    }
    void setRecord(const std::string &record) {
        this->record = record;
    }
    void setImporto(int importo) {
        this->importo = importo;
    }
        void setDescrizione(const std::string &descrizione) {
        this->descrizione = descrizione;
    }
        void setData(const std::string &data) {
        this->data = data;
    }

    protected:
        std::string data;
        std::string descrizione;
        int importo;
        std::string record;//la stringa che deve contenere tutti i dati da salvare sul csv(es: tipoMovimento;data;descrizione;importo)

};



#endif //MOVIMENTO_H
