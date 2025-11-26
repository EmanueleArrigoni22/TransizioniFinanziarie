//
// Created by Emanuele Arrigoni on 26/11/25.
//
#include <gtest/gtest.h>
#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"
//Test per controllare la corretta creazione dell'oggetto Entrata
TEST(TestMovimenti,TestCreazioneEntrata) {
    std::unique_ptr<Entrata> e = std::make_unique<Entrata>("26/11/2025", "Regalo di compleanno", 100);
    EXPECT_EQ(e->getData(), "26/11/2025");
    EXPECT_EQ(e->getDescrizione(), "Regalo di compleanno");
    EXPECT_EQ(e->getImporto(), 100);

}
//Test per controllare che nel caso venga inserito un importo negativo(non valido) questo venga convertito in positivo, starà poi alla funzione effettoSaldo() applicare il movimento nella maniera corretta
TEST(TestMovimenti,TestCreazioneEntrataNegativa) {
    std::unique_ptr<Entrata> e = std::make_unique<Entrata>("26/11/2025", "Regalo di compleanno", -100);
    EXPECT_EQ(e->getImporto(), 100);
}


TEST(TestMovimenti,TestCreazioneUscita) {
    std::unique_ptr<Uscita> u = std::make_unique<Uscita>("26/11/2025", "Abbonamento Spotify", 6.50);
    EXPECT_EQ(u->getData(), "26/11/2025");
    EXPECT_EQ(u->getDescrizione(), "Abbonamento Spotify");
    EXPECT_EQ(u->getImporto(), 6.50);

}

TEST(TestMovimenti,TestCreazioneUscitaNegativa) {
    std::unique_ptr<Uscita> e = std::make_unique<Uscita>("26/11/2025", "Abbonamento Spotify", -6.50);
    EXPECT_EQ(e->getImporto(), 6.50);
}