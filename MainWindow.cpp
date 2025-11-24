#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QInputDialog>
#include <QDateEdit>
#include <QLineEdit>
#include <QDoubleSpinBox>

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

    connect(comboConti, &QComboBox::currentIndexChanged,
            this, &MainWindow::onContoSelezionato);

    // Label saldo
    saldoLabel = new QLabel("Saldo: --", this);
    mainLayout->addWidget(saldoLabel);

    // Bottoni
    btnNuovoConto = new QPushButton("Crea nuovo conto", this);
    btnEntrata = new QPushButton("Registra Entrata", this);
    btnUscita = new QPushButton("Registra Uscita", this);

    mainLayout->addWidget(btnNuovoConto);
    mainLayout->addWidget(btnEntrata);
    mainLayout->addWidget(btnUscita);

    connect(btnNuovoConto, &QPushButton::clicked,
            this, &MainWindow::creaNuovoConto);

    connect(btnEntrata, &QPushButton::clicked,
            this, &MainWindow::registraEntrata);

    connect(btnUscita, &QPushButton::clicked,
            this, &MainWindow::registraUscita);
}

MainWindow::~MainWindow() {}

void MainWindow::creaNuovoConto()
{
        bool ok;
        QString nome = QInputDialog::getText(this, "Nuovo Conto",
                                             "Nome del conto:",
                                             QLineEdit::Normal,
                                             "", &ok);

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
