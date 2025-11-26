//
// Created by Emanuele Arrigoni on 26/11/25.
//
#include <gtest/gtest.h>
#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"

//Sto controllando che il saldo, alla creazione del Conto Corrente sia pari a 0
TEST(ContoCorrenteTest, SaldoIniziale) {
    std::unique_ptr<ContoCorrente> c;
    c = std::make_unique<ContoCorrente>("Mario");
    EXPECT_EQ(c->getSaldo(), 0);
}
//controllo che venga aggiornato il conto corrente quando viene aggiornato il conto corrente con un entrata!
TEST(ContoCorrenteTest, RegistraEntrata) {
    std::unique_ptr<ContoCorrente> c;
    c = std::make_unique<ContoCorrente>("Mario");
    std::unique_ptr<Entrata> e;
    e = std::make_unique<Entrata>("stipendio", "2024-05-01", 1000);
    c->registraMovimento(std::move(e));

    EXPECT_EQ(c->getSaldo(), 1000); //il conto dovrà mostrare che il saldo corrente è pari a 1000
}

//Testo sia entrata che uscita in questo caso!
TEST(ContoCorrenteTest, RegistraUscita) {
    std::unique_ptr<ContoCorrente> c;
    c = std::make_unique<ContoCorrente>("Mario");
    std::unique_ptr<Entrata> e;
    e = std::make_unique<Entrata>("stipendio", "2024-05-01", 1000);
    std::unique_ptr<Uscita> u = std::make_unique<Uscita>("affitto", "2024-05-02", 500);


    c->registraMovimento(std::move(e));
    c->registraMovimento(std::move(u));

    EXPECT_EQ(c->getSaldo(), 500);
}

TEST(ContoCorrenteTest,ContoNegativo) {
    std::unique_ptr<ContoCorrente> c;
    c = std::make_unique<ContoCorrente>("Mario");
    std::unique_ptr<Uscita> u = std::make_unique<Uscita>("affitto", "2024-05-02", 500);
    c->registraMovimento(std::move(u));
    EXPECT_EQ(c->getSaldo(), -500);

}
