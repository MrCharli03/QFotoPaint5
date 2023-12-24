#include "pinchar_estirar.h"
#include "ui_pinchar_estirar.h"
#include "imagenes.h"

int pe_nfoto;
int pe_cx, pe_cy;
double pe_radio, pe_grado;

void cb_pinchar_estirar(int evento, int x, int y, int flags, void *pt){
    if(flags==EVENT_FLAG_LBUTTON){
        pe_cx=x;
        pe_cy=y;
        ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
    }
}

pinchar_estirar::pinchar_estirar(int numfoto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinchar_estirar)
{
    ui->setupUi(this);
    pe_nfoto= numfoto;
    pe_radio= 200;
    pe_grado= pe_radio*pe_radio*30/1000.0;
    pe_cx= foto[numfoto].img.cols/2;
    pe_cy= foto[numfoto].img.rows/2;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
    setMouseCallback("Pinchar/estirar", cb_pinchar_estirar);
}



pinchar_estirar::~pinchar_estirar()
{
    delete ui;
}

void pinchar_estirar::on_horizontalSlider_valueChanged(int value)
{
    pe_grado= pe_radio*pe_radio*30/1000.0;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
}

void pinchar_estirar::on_horizontalSlider_2_valueChanged(int value)
{
    pe_radio = value;
    pe_grado= pe_radio*pe_radio*ui->horizontalSlider->value()/1000.0;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);

}

void pinchar_estirar::on_pinchar_estirar_accepted()
{
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado, true);
    destroyWindow("Pinchar/estirar");
    mostrar(pe_nfoto);
}

void pinchar_estirar::on_pinchar_estirar_rejected()
{
    destroyWindow("Pinchar/estirar");
}
