#include "copiar_video_ui.h"
#include "ui_copiar_video_ui.h"
#include <QFileDialog>
#include "video.h"
#include <QMessageBox>
#include "imagenes.h"

copiar_video_ui::copiar_video_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::copiar_video_ui)
{
    ui->setupUi(this);
    matiz= 0;
    sat = 1.0;
    lum= 1.0;
    numtipo= 0;
    numcamara = 0;
}

copiar_video_ui::~copiar_video_ui()
{
    delete ui;
}

void copiar_video_ui::on_pushButton_clicked()
{
    QString nombre = QFileDialog::getOpenFileName(this, "Video a abrir", ".", QString::fromStdString(FiltroVideo));
    if(!cap.open(nombre.toLatin1().data())){
        QMessageBox::information(this, "Error al abrir el archivo", "No se ha podido abrir el archivo");
        numcamara = 0;
    }
    else{
        numcamara = -1;
    }
}
void copiar_video_ui::on_pushButton_2_clicked()
{
    numcamara = ui->spinBox->value();
    if(!cap.open(numcamara)){
        QMessageBox::information(this, "Error al abrir cámara",
                                 "No se ha podido abrir la cámara");

    }
}

void copiar_video_ui::on_spinBox_2_valueChanged(int arg1)
{
    matiz = arg1;
}

void copiar_video_ui::on_doubleSpinBox_valueChanged(double arg1)
{
    sat = arg1;
}

void copiar_video_ui::on_doubleSpinBox_2_valueChanged(double arg1)
{
    lum = arg1;
}

void copiar_video_ui::on_copiar_video_ui_accepted()
{
    if(!cap.isOpened()){
        QMessageBox::information(this, "Error fuente de video no seleccionada",
                                 "Debe seleccionar primero la entrada");
        return;
    }
    QString nombre = QFileDialog::getSaveFileName(this, "Video a abrir",
                                                  ".", QString::fromStdString(FiltroVideo));
    if(!nombre.isEmpty()){
        double fps = cap.get(CAP_PROP_FPS);
        if(fps<=0) fps= 25;
        Mat frame;
        if(cap.read(frame)){
            if(!wri.open(nombre.toLatin1().data(), VideoWriter::fourcc('D','I','V','X'),
                         fps, frame.size())){
                QMessageBox::information(this, "Error no se puede crear el video",
                                         "No se puede crear el video de salida");
                return;
            }
            while(waitKey(1) == -1 && cap.read(frame)){
                Mat efecto;
                if(numtipo == 0)
                    efecto = matsatlum(frame, sat, lum, matiz);
                else{
                    double radio = ui->doubleSpinBox_4->value();
                    efecto = op_pinchar_estirar(frame,
                                            ui->spinBox_3->value(),
                                            ui->spinBox_4->value(),
                                            radio,
                                            radio*radio*ui->doubleSpinBox_3->value()/1000.0);
                }
                if(ui->checkBox->isChecked())
                    matiz= (matiz+4)% 256;
                imshow("Frame", efecto);
                wri.write(efecto);
            }
            wri.release();
            destroyWindow("Frame");
        }
    }
}

void copiar_video_ui::on_tabWidget_currentChanged(int index)
{
    numtipo = index;
}
