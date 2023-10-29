#include "capturarvideo.h"
#include "ui_capturarvideo.h"

capturarvideo::capturarvideo(string nombre,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capturarvideo)
{
    ui->setupUi(this);
    cap.open(nombre);
    if (cap.isOpened()){
        Mat frame;
        cap.read(frame);
        imshow("Frame", frame);
        int longitud =cap.get(CAP_PROP_FRAME_COUNT);
        ui ->spinBox->setMaximum(longitud-1);
        ui->horizontalSlider_3->setMaximum(longitud-1);
    }
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

capturarvideo::~capturarvideo()
{
    delete ui;
}

bool capturarvideo::isOpen()
{
    return cap.isOpened();
}

void capturarvideo::on_spinBox_valueChanged(int arg1)
{
  ui->horizontalSlider_3->setValue(arg1);
}

void capturarvideo::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    cap.set(CAP_PROP_POS_FRAMES,value);
    Mat img;
     if (cap.read(img))
         imshow("Frame",img);
     else {
         qDebug("Error al leer frame %d",value);
     }
}

void capturarvideo::on_capturarvideo_accepted()
{

    cap.set(CAP_PROP_POS_FRAMES,ui->spinBox->value());
    Mat frame;
    if (cap.read(frame))
        crear_nueva(primera_libre(),frame);
    destroyWindow("Frame");
}

void capturarvideo::on_capturarvideo_rejected()
{
    destroyWindow("Frame");
}
