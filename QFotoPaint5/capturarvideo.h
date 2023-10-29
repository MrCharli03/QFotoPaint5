#ifndef CAPTURARVIDEO_H
#define CAPTURARVIDEO_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class capturarvideo;
}

class capturarvideo : public QDialog
{
    Q_OBJECT

public:
    explicit capturarvideo(string nombre, QWidget *parent = nullptr);
    ~capturarvideo();
    bool isOpen();

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_horizontalSlider_3_valueChanged(int value);

    void on_capturarvideo_accepted();

    void on_capturarvideo_rejected();

private:
    Ui::capturarvideo *ui;
    VideoCapture cap;
};

#endif // CAPTURARVIDEO_H
