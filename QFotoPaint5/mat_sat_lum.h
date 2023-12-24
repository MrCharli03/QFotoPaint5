#ifndef MAT_SAT_LUM_H
#define MAT_SAT_LUM_H

#include <QDialog>

namespace Ui {
class mat_sat_lum;
}

class mat_sat_lum : public QDialog
{
    Q_OBJECT

public:
    explicit mat_sat_lum(int numfoto, QWidget *parent = nullptr);
    ~mat_sat_lum();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_mat_sat_lum_rejected();

    void on_mat_sat_lum_accepted();

private:
    int nfoto;
    double sat, lum;
    int matiz;
    Ui::mat_sat_lum *ui;
};

#endif // MAT_SAT_LUM_H
