//
// Created by Emanuele Arrigoni on 16/11/25.
//

#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include <string>


class Movimento {
public:
    explicit Movimento(const std::string &data, const std::string &descrizione, double importo);
    virtual ~Movimento() = default;
    std::string getData() const {
        return data;
    }
    std::string getDescrizione() const {
        return descrizione;
    }
    double getImporto() const {
        return importo;
    }
    std::string getRecord() const {
        return record;
    }
    void setRecord(const std::string &record) {
        this->record = record;
    }
    void setImporto(double importo) {
        this->importo = importo;
    }
        void setDescrizione(const std::string &descrizione) {
        this->descrizione = descrizione;
    }
        void setData(const std::string &data) {
        this->data = data;
    }

    virtual double effettoSaldo() const = 0;//metodo per specificare, tramite polimorfismo, l'effetto dello specifico movimento sul saldo(devo sottrarre o sommare al saldo corrente??)

    protected:
        std::string data;
        std::string descrizione;
        double importo;
        std::string record;//la stringa che deve contenere tutti i dati da salvare sul csv(es: tipoMovimento;data;descrizione;importo)

};



#endif //MOVIMENTO_H
