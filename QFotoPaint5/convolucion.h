#ifndef CONVOLUCION_H
#define CONVOLUCION_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class convolucion;
}

class convolucion : public QDialog
{
    Q_OBJECT

public:
    explicit convolucion(int numfoto, int numres,
                         QWidget *parent = nullptr);
    ~convolucion();

private slots:
    void on_pushButton_clicked();

    void on_convolucion_accepted();

    void on_convolucion_rejected();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    void actualizar();
    int nfoto, nres;
    double mult, suma;
    Mat M;
    Ui::convolucion *ui;
};

#endif // CONVOLUCION_H
