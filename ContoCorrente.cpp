//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "ContoCorrente.h"


ContoCorrente::ContoCorrente(std::string nominativo):saldoCorrente(0),nominativo(nominativo){
   this -> path = "'/Users/emanuelearrigoni/Desktop/1° anno ingegneria/Laboratorio_Programmazione/transazioni_finanziarie/" + nominativo;
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile creare il file!" << std::endl;
    }
    file.close();
}

bool ContoCorrente::registraMovimento(const Movimento &m) {
    bool successo = false;
    if (m.getRecord() != "") {
        operazioni.push_back(std::make_unique<std::string>(m.getRecord()));
        std::ofstream file(path);
        if (!file.is_open()) {
            std::cerr << "Errore: impossibile creare il file!" << std::endl;
        }
        file << m.getRecord();
        this->saldoCorrente += m.getImporto();//TODO capire come aggiungere o togliere dal saldo in base al tipo di movimento(entrata o uscita)
        successo = true;
    }
    return successo;
}
