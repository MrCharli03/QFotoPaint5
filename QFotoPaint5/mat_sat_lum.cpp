#include "mat_sat_lum.h"
#include "ui_mat_sat_lum.h"
#include "imagenes.h"

mat_sat_lum::mat_sat_lum(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mat_sat_lum)
{
    ui->setupUi(this);
    nfoto = numfoto;
    lum=1;
    sat=1;
    matiz=0;
}

mat_sat_lum::~mat_sat_lum()
{
    delete ui;
}

void mat_sat_lum::on_horizontalSlider_valueChanged(int value)
{
    sat= value/100.0;
    ver_mat_sat_lum(nfoto, sat, lum, matiz);
}

void mat_sat_lum::on_horizontalSlider_2_valueChanged(int value)
{
    lum= value/100.0;
    ver_mat_sat_lum(nfoto, sat, lum, matiz);
}

void mat_sat_lum::on_dial_valueChanged(int value)
{
    matiz=value;
    ver_mat_sat_lum(nfoto, sat, lum, matiz);
}

void mat_sat_lum::on_mat_sat_lum_rejected()
{
    mostrar(nfoto);
}

void mat_sat_lum::on_mat_sat_lum_accepted()
{
    ver_mat_sat_lum(nfoto, sat, lum, matiz, true);
    mostrar(nfoto);
}
