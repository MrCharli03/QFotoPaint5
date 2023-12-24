#ifndef COPIAR_VIDEO_UI_H
#define COPIAR_VIDEO_UI_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class copiar_video_ui;
}

class copiar_video_ui : public QDialog
{
    Q_OBJECT

public:
    explicit copiar_video_ui(QWidget *parent = nullptr);
    ~copiar_video_ui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_copiar_video_ui_accepted();

    void on_tabWidget_currentChanged(int index);

private:
    VideoCapture cap;
    VideoWriter wri;
    int numcamara;
    int numtipo;
    int matiz;
    double sat, lum;
    Ui::copiar_video_ui *ui;
};

#endif // COPIAR_VIDEO_UI_H
