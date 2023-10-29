#ifndef AJUSTELINEAL_H
#define AJUSTELINEAL_H

#include <QDialog>

namespace Ui {
class ajustelineal;
}

class ajustelineal : public QDialog
{
    Q_OBJECT

public:
    explicit ajustelineal(int numfoto, QWidget *parent = nullptr);
    ~ajustelineal();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_ajustelineal_accepted();

    void on_ajustelineal_rejected();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    void actualizar();
    int nfoto;
    Ui::ajustelineal *ui;
};

#endif // AJUSTELINEAL_H
