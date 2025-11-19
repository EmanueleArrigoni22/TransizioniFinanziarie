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
