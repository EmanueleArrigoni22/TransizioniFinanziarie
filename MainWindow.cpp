#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QInputDialog>
#include <QDateEdit>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Widget centrale
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Combo conti
    comboConti = new QComboBox(this);
    mainLayout->addWidget(comboConti);

    connect(comboConti, &QComboBox::currentIndexChanged,this, &MainWindow::onContoSelezionato);

    // Label saldo
    saldoLabel = new QLabel("Saldo: --", this);
    mainLayout->addWidget(saldoLabel);

    // Bottoni
    btnNuovoConto = new QPushButton("Crea nuovo conto", this);
    btnEntrata = new QPushButton("Registra Entrata", this);
    btnUscita = new QPushButton("Registra Uscita", this);

    recuperaConto();

    mainLayout->addWidget(btnNuovoConto);
    mainLayout->addWidget(btnEntrata);
    mainLayout->addWidget(btnUscita);

    connect(btnNuovoConto, &QPushButton::clicked,this, &MainWindow::creaNuovoConto);

    connect(btnEntrata, &QPushButton::clicked,this, &MainWindow::registraEntrata);

    connect(btnUscita, &QPushButton::clicked,this, &MainWindow::registraUscita);
}

MainWindow::~MainWindow() {}

void MainWindow::recuperaConto() {
        std::string path = "../file_csv";
        int i = 0;
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
                if (entry.is_regular_file() && entry.path().extension() == ".csv") {
                        //adesso creo e popolo i conti corrente già esistenti
                        conti.push_back(std::make_unique<ContoCorrente>(entry.path().stem().string()));
                        leggiDaiConti(entry.path(), i);
                        QString nomefile = QString::fromStdString(entry.path().stem().string());
                        comboConti->addItem(nomefile);
                        i++;
                }

        }
}

void MainWindow::leggiDaiConti(const std::filesystem::path& filepath, int index) {

        std::ifstream file(filepath); // Apro il file per la lettura
        int numeroRiga = 0;
        // Controllo se il file esiste nella directory
        if (!file.is_open()) {
                std::cerr << "Errore: Impossibile aprire il file " << filepath << std::endl;
        }
        std::string riga;
        while (std::getline(file, riga)) {

                numeroRiga++; //Parto dalla seconda riga; la prima è la legenda!
                // Se la riga è vuota, la salto
                if (riga.empty()) continue;
                // 1. SALTO L'INTESTAZIONE
                // Se sono alla riga 1, controllo se inizia con "Tipo" o caratteri non numerici
                if (numeroRiga == 1) {
                        // Controllo banale: se la riga contiene "Tipo" o "Importo", la salto
                        if (riga.find("Tipo") != std::string::npos || riga.find("Importo") != std::string::npos) {
                                continue;
                        }
                }

                std::stringstream ss(riga); // Trasforma la riga in uno stream gestibile(è una sorta di split del java)
                std::string tipo;
                std::string data;
                std::string descrizione;
                std::string importo;

                // Queste sono le vere e proprio split
                if (std::getline(ss, tipo, ';')) {
                        std::cout << tipo << std::endl;
                }

                if (std::getline(ss, data, ';')) {
                        std::cout << data << std::endl;

                }
                if (std::getline(ss, descrizione, ';')) {
                        std::cout << descrizione << std::endl;

                }
                if (std::getline(ss, importo, ';')) {
                        std::cout << importo << std::endl;

                }

                try {
                        double valore = 0.0;

                        // 2. FIX PUNTO VS VIRGOLA (Metodo Sicuro)
                        // Usiamo uno stream temporaneo forzando il locale "C" (Classic) che usa sempre il punto.
                        std::stringstream convertitore(importo);
                        convertitore.imbue(std::locale::classic());
                        convertitore >> valore;

                        // Se la conversione è fallita (es. stringa vuota o testo strano)
                        if (convertitore.fail()) {
                                throw std::invalid_argument("Errore conversione");
                        }

                        if (tipo == "Entrata") {
                                conti[index]->caricaMovimento(std::make_unique<Entrata>(data, descrizione, valore));
                        }
                        else {
                                conti[index]->caricaMovimento(std::make_unique<Uscita>(data, descrizione, valore));
                        }
                }
                catch (const std::exception& e) {
                        // Stampiamo importoStr tra parentesi quadre per vedere se ci sono spazi strani
                        std::cerr << "Errore riga " << numeroRiga << ": impossibile convertire [" << importo << "]" << std::endl;
                }



        }

       /* try {
                file.close();
                // Tento di rimuovere il file
                // Restituisce true se ha cancellato, false se il file non c'era
                bool rimosso = std::filesystem::remove(filepath);

                if (rimosso) {
                        std::cout << "File eliminato con successo." << std::endl;
                } else {
                        std::cout << "Il file non esisteva." << std::endl;
                }
        }
        catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Errore del filesystem: " << e.what() << std::endl;
        }*/
}
void MainWindow::creaNuovoConto()
{
        bool ok;
        QString nome = QInputDialog::getText(this, "Nuovo Conto","Intestatario del conto:",QLineEdit::Normal,"", &ok);

        if (!ok || nome.isEmpty())
                return;

        conti.push_back(std::make_unique<ContoCorrente>(nome.toStdString()));
        comboConti->addItem(nome);

        contoAttivo = conti.size() - 1;
        comboConti->setCurrentIndex(contoAttivo);

        aggiornaSaldo();
}

void MainWindow::onContoSelezionato(int index)
{
        contoAttivo = index;
        aggiornaSaldo();
}

void MainWindow::registraEntrata()
{
        if (contoAttivo < 0) return;

        QString data, desc;
        double importo;

        if (!apriDialogoMovimento(data, desc, importo))
                return;

        auto mov = std::make_unique<Entrata>(
            data.toStdString(), desc.toStdString(), importo
        );

        conti[contoAttivo]->registraMovimento(std::move(mov));

        aggiornaSaldo();

}


void MainWindow::registraUscita()
{
        if (contoAttivo < 0) return;

        QString data, desc;
        double importo;

        if (!apriDialogoMovimento(data, desc, importo))
                return;

        auto mov = std::make_unique<Uscita>(
            data.toStdString(), desc.toStdString(), importo
        );

        conti[contoAttivo]->registraMovimento(std::move(mov));

        aggiornaSaldo();


}

bool MainWindow::apriDialogoMovimento(QString &data,
                                      QString &desc,
                                      double &importo)
{
        QDialog dlg(this);
        dlg.setWindowTitle("Nuovo Movimento");

        QFormLayout layout(&dlg);

        QDateEdit *d = new QDateEdit(QDate::currentDate());
        QLineEdit *descr = new QLineEdit();
        QDoubleSpinBox *imp = new QDoubleSpinBox();
        imp->setMaximum(1000000);

        layout.addRow("Data:", d);
        layout.addRow("Descrizione:", descr);
        layout.addRow("Importo:", imp);

        QDialogButtonBox b(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        layout.addWidget(&b);

        QObject::connect(&b, &QDialogButtonBox::accepted, &dlg, &QDialog::accept);
        QObject::connect(&b, &QDialogButtonBox::rejected, &dlg, &QDialog::reject);

        if (dlg.exec() == QDialog::Accepted) {
                data = d->date().toString("dd/MM/yyyy");
                desc = descr->text();
                importo = imp->value();
                return true;
        }

        return false;
}

void MainWindow::aggiornaSaldo()
{
        if (contoAttivo < 0) return;

        double saldo = conti[contoAttivo]->getSaldo();
        saldoLabel->setText("Saldo: " + QString::number(saldo) + " €");
}
