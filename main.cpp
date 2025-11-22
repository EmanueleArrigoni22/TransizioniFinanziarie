
#include <iostream>
#include <fstream>
#include <string>

#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"

int main() {

    std::unique_ptr<ContoCorrente> contoCorrente;
    contoCorrente = std::make_unique<ContoCorrente>("Mario Rossi");
    std::unique_ptr<Entrata> entrata;
    entrata = std::make_unique<Entrata>("22/11/2025","Regalo di Compleanno",500);
    contoCorrente->registraMovimento(std::move(entrata));
    std::unique_ptr<Uscita> uscita;
    uscita = std::make_unique<Uscita>("22/11/2025","Spese compleanno",200);
    contoCorrente->registraMovimento(std::move(uscita));


    return 0;
}
