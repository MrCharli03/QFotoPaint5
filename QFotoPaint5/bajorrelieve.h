#ifndef BAJORRELIEVE_H
#define BAJORRELIEVE_H

#include <QDialog>

namespace Ui {
class Bajorrelieve;
}

class Bajorrelieve : public QDialog
{
    Q_OBJECT

public:
    explicit Bajorrelieve(int numfoto, int numres, QWidget *parent = nullptr);
    ~Bajorrelieve();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_Bajorrelieve_accepted();

    void on_Bajorrelieve_rejected();

private:
    int nfoto;
    int nres;
    double angulo;
    double grado;
    int nfondo;
    Ui::Bajorrelieve *ui;
};

#endif // BAJORRELIEVE_H
