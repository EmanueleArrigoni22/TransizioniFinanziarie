#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include <vector>
#include <memory>

// Le tue classi già esistenti
#include "ContoCorrente.h"
#include "Movimento.h"
#include "Entrata.h"
#include "Uscita.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT//è una macro di QT che permette al compilatore di riconoscere che questa non è una semplice classe c++ ma deve comportarsi in un modo particolare(per esempio linkare le funzioni ai bottoni)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void creaNuovoConto();//slot QT
    void onContoSelezionato(int index);//slot QT
    void registraEntrata();//slot QT
    void registraUscita();//slot QT
    //Queste slot funzionano solamente se esiste il comando Q_OBJECT

private:
    // GUI components
    QComboBox* comboConti;
    QLabel* saldoLabel;
    QPushButton* btnNuovoConto;
    QPushButton* btnEntrata;
    QPushButton* btnUscita;

    // Model
    std::vector<std::unique_ptr<ContoCorrente>> conti;
    int contoAttivo = -1;

    // Utility
    void aggiornaSaldo();
    bool apriDialogoMovimento(QString &data, QString &desc, double &importo);
};

#endif // MAINWINDOW_H
