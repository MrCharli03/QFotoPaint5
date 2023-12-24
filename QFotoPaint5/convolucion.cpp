#include "convolucion.h"
#include "ui_convolucion.h"

convolucion::convolucion(int numfoto, int numres, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::convolucion)
{
    ui->setupUi(this);
    nfoto = numfoto;
    nres = numres;
    M.create(5, 5, CV_64FC1);
    actualizar();
}

void convolucion::actualizar(){
    suma= ui->doubleSpinBox_2->value();
    mult= ui->doubleSpinBox->value();
    for(int y=0; y<5;y++)
        for(int x=0; x<5; x++){
           double val= ui->tableWidget->item(y,x)->text().toDouble();
           M.at<double>(y, x)= val;
           ui->tableWidget->item(y,x)->setText(QString::number(val));
        }
}
convolucion::~convolucion()
{
    delete ui;
}

void convolucion::on_pushButton_clicked()
{
    actualizar();
    ver_convolucion(nfoto, nres, M, mult, suma);
}

void convolucion::on_convolucion_accepted()
{
    actualizar();
    ver_convolucion(nfoto, nres, M, mult, suma, true);
    destroyWindow("Convolución");
}

void convolucion::on_convolucion_rejected()
{
    destroyWindow("Convolución");
}

void convolucion::on_pushButton_2_clicked()
{
    double T[5][5]= {{0,0,0,0,0},
                    {0,-1,0,1,0},
                    {0,-1,0,1,0},
                    {0,-1,0,1,0},
                    {0,0,0,0,0}};
    for(int y= 0; y<5; y++)
        for(int x= 0; x<5; x++)
            ui->tableWidget->item(y, x)->setText(QString::number(T[y][x]));
    ui->doubleSpinBox->setValue(1);
    ui->doubleSpinBox_2->setValue(128);
}

void convolucion::on_pushButton_3_clicked()
{
    double T[5][5]= {{0,0,0,0,0},
                    {0,-1-1,-1,0},
                    {0,-1,8,-1,0},
                    {0,-1,-1,-1,0},
                    {0,0,0,0,0}};
    for(int y= 0; y<5; y++)
        for(int x= 0; x<5; x++)
            ui->tableWidget->item(y, x)->setText(QString::number(T[y][x]));
    ui->doubleSpinBox->setValue(1);
    ui->doubleSpinBox_2->setValue(128);
}

void convolucion::on_pushButton_4_clicked()
{
    double T[5][5]= {{0,0,0,0,0},
                    {0,-1-1,-1,0},
                    {0,-1,9,-1,0},
                    {0,-1,-1,-1,0},
                    {0,0,0,0,0}};
    for(int y= 0; y<5; y++)
        for(int x= 0; x<5; x++)
            ui->tableWidget->item(y, x)->setText(QString::number(T[y][x]));
    ui->doubleSpinBox->setValue(1);
    ui->doubleSpinBox_2->setValue(0);
}

void convolucion::on_pushButton_5_clicked()
{
    for(int y= 0; y<5; y++)
        for(int x= 0; x<5; x++)
            ui->tableWidget->item(y, x)->setText("1");
    ui->doubleSpinBox->setValue(1.0/25);
    ui->doubleSpinBox_2->setValue(0);
}
