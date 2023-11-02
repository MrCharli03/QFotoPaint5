#include "bajorrelieve.h"
#include "ui_bajorrelieve.h"
#include "imagenes.h"

Bajorrelieve::Bajorrelieve(int numfoto, int numres, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bajorrelieve)
{
    ui->setupUi(this);
    nfoto = numfoto;
    nres = numres;
    angulo = 0;
    grado = 1;
    nfondo = 3;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

Bajorrelieve::~Bajorrelieve()
{
    delete ui;
}

void Bajorrelieve::on_horizontalSlider_valueChanged(int value)
{
    grado = value/100.0;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_dial_valueChanged(int value)
{
    angulo = value;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_radioButton_clicked()
{
    nfondo = 0;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_radioButton_2_clicked()
{
    nfondo= 1;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_radioButton_3_clicked()
{
    nfondo= 2;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_radioButton_4_clicked()
{
    nfondo= 3;
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo);
}

void Bajorrelieve::on_Bajorrelieve_accepted()
{
    ver_bajorrelieve(nfoto, nres, angulo, grado, nfondo, true);
    destroyWindow("Bajorrelieve");
}

void Bajorrelieve::on_Bajorrelieve_rejected()
{
    destroyWindow("Bajorrelieve");
}
