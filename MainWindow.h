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
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void creaNuovoConto();
    void onContoSelezionato(int index);
    void registraEntrata();
    void registraUscita();

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
