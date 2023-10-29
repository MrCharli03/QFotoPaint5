#include "ajustelineal.h"
#include "ui_ajustelineal.h"
#include "imagenes.h"

ajustelineal::ajustelineal(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajustelineal)
{
    ui->setupUi(this);
    nfoto=numfoto;
    actualizar();
}

void ajustelineal::actualizar()
{
    if(ui->checkBox->isChecked())
        ver_ajuste_lineal(nfoto, ui->horizontalSlider->value(), ui->horizontalSlider_2->value());
    else {
        mostrar(nfoto);
    }
}

ajustelineal::~ajustelineal()
{
    delete ui;
}

void ajustelineal::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualizar();
}

void ajustelineal::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
    actualizar();
}

void ajustelineal::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualizar();
}

void ajustelineal::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
    actualizar();
}

void ajustelineal::on_checkBox_stateChanged(int arg1)
{
    actualizar();
}

void ajustelineal::on_ajustelineal_accepted()
{
    ver_ajuste_lineal(nfoto, ui->horizontalSlider->value(), ui->horizontalSlider_2->value(),true);
}



void ajustelineal::on_ajustelineal_rejected()
{
    mostrar(nfoto);
}




