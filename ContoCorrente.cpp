//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "ContoCorrente.h"
#include <fstream>
#include<iostream>
#include <string>


ContoCorrente::ContoCorrente(std::string const &nominativo):saldoCorrente(0),nominativo(nominativo){
    std:: cout << "ContoCorrente constructor" << std::endl;
    this->path = "../file_csv/" + nominativo + ".csv";

    // 2. Controllo se il file esiste GIÀ
    if (std::filesystem::exists(this->path)) {
        // Il file esiste: NON fare nulla (non aprirlo, non sovrascriverlo)
        std::cout << "Caricato conto esistente: " << nominativo << std::endl;
    }
    else {
        // Il file NON esiste: È un nuovo conto, crealo ora.
        std::ofstream file(this->path);
        if (!file.is_open()) {
            std::cerr << "Errore: impossibile creare il file!" << std::endl;
        } else {
            file << "Tipo;Data;Descrizione;Importo;Saldo\n";
            file.close();
            std::cout << "Creato nuovo file per: " << nominativo << std::endl;
        }
    }

}


void ContoCorrente::applicaMovimento(Movimento* m) {

    operazioni.push_back(std::make_unique<std::string>(m->getRecord()));
    this->saldoCorrente += m->effettoSaldo();

    if (this->saldoCorrente < 0) {
        std::cout << "!! ATTENZIONE: Saldo negativo per " << this->nominativo << std::endl;
    }
}



bool ContoCorrente::registraMovimento(std::unique_ptr<Movimento> m) {
    bool successo = false;
    if (m->getRecord() != "") {

        applicaMovimento(m.get());// passo il raw pointer alla funzione privata(devo solo leggere i dati, basta il puntatore grezzo)
        std::ofstream file(path,std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Errore: impossibile creare il file!" << std::endl;
        }
        file << m->getRecord() + ";" + std::to_string(saldoCorrente);
        file << "\n";
        successo = true;
        if (this->saldoCorrente < 0) {
            std::cout << "!!ATTENZIONE "<< this->nominativo << " !! Hai raggiunto un saldo Negativo!! Contatta al più presto la filiare" << std::endl;
        }
    }
    return successo;
}

bool ContoCorrente::caricaMovimento(std::unique_ptr<Movimento> m) {
    bool successo = false;
    if (m->getRecord() != "") {
        applicaMovimento(m.get());
        successo = true;
    }
    return successo;
}

ContoCorrente:: ~ContoCorrente() {}
