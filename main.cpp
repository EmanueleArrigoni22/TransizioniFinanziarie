
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Percorso completo del file (puoi personalizzarlo)
    std::string path = "/Users/emanuelearrigoni/Desktop/prova.csv";
    // Su Linux/Mac sarebbe tipo "/home/user/dati.csv"
    std::ofstream file(path);

    // Verifica che il file sia stato aperto correttamente
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile creare il file!" << std::endl;
        return 1;
    }

    // Scrittura di alcuni dati CSV
    file << "Nome,Cognome,Età\n";
    file << "Mario,Rossi,30\n";
    file << "Luca,Bianchi,25\n";
    file << "Ana,Verdi,28\n";

    file.close();

    std::cout << "File CSV creato correttamente in:\n" << path << std::endl;

    return 0;
}
