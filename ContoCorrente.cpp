//
// Created by Emanuele Arrigoni on 16/11/25.
//

#include "ContoCorrente.h"
#include <fstream>
#include<iostream>
#include <string>


ContoCorrente::ContoCorrente(std::string const &nominativo):saldoCorrente(0),nominativo(nominativo){
    std:: cout << "ContoCorrente constructor" << std::endl;
   this -> path = "/Users/emanuelearrigoni/Desktop/1°_anno_ingegneria/Laboratorio_Programmazione/transazioni_finanziarie/file_csv/" + nominativo +".csv";
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile creare il file!" << std::endl;
    }
    file << "Data;Descrizione;Tipo;Importo;Saldo\n";
    file.close();
    std::cout << nominativo << std::endl;
}

bool ContoCorrente::registraMovimento(std::unique_ptr<Movimento> m) {
    bool successo = false;
    if (m->getRecord() != "") {
        operazioni.push_back(std::make_unique<std::string>(m->getRecord()));
        std::ofstream file(path,std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Errore: impossibile creare il file!" << std::endl;
        }

        this->saldoCorrente += m->effettoSaldo();
        file << m->getRecord() + ";" + std::to_string(saldoCorrente);
        file << "\n";
        successo = true;
        if (this->saldoCorrente < 0) {
            std::cout << "!!ATTENZIONE "<< this->nominativo << " !! Hai raggiunto un saldo Negativo!! Contatta al più presto la filiare" << std::endl;
        }
    }
    return successo;
}

ContoCorrente:: ~ContoCorrente() {}
