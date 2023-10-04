#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,240,80);
    trem2 = new Trem(2,590,80);

    //---mudanças no codigo original
    trem3 = new Trem(3,150,200);
    trem4 = new Trem(4,460,320);
    trem5 = new Trem(5,870,200);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    //---mudanças no codigo original
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

    ui->display1->setText(QString::number(ui->horizontalSlider_trem1->value()) + " km/h");
    ui->display2->setText(QString::number(ui->horizontalSlider_trem2->value()) + " km/h");
    ui->display3->setText(QString::number(ui->horizontalSlider_trem3->value()) + " km/h");
    ui->display4->setText(QString::number(ui->horizontalSlider_trem4->value()) + " km/h");
    ui->display5->setText(QString::number(ui->horizontalSlider_trem5->value()) + " km/h");
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){


    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    //---mudanças no codigo original
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */


//void MainWindow::on_pushButton_clicked()
//{
//    trem1->start();
//    trem2->start();
//}

///*
// * Ao clicar, trens param execução
// */
//void MainWindow::on_pushButton_2_clicked()
//{
//    trem1->terminate();
//    trem2->terminate();
//}

void MainWindow::on_horizontalSlider_trem1_valueChanged(int value)
{
    trem1->setVelocidade(value);
    ui->display1->setText(QString::number(value) + " km/h");
}


void MainWindow::on_horizontalSlider_trem2_valueChanged(int value)
{
    trem2->setVelocidade(value);
    ui->display2->setText(QString::number(value) + " km/h");
}

void MainWindow::on_horizontalSlider_trem3_valueChanged(int value)
{
      trem3->setVelocidade(value);
      ui->display3->setText(QString::number(value) + " km/h");
}


void MainWindow::on_horizontalSlider_trem4_valueChanged(int value)
{
    trem4->setVelocidade(value);
    ui->display4->setText(QString::number(value) + " km/h");
}


void MainWindow::on_horizontalSlider_trem5_valueChanged(int value)
{
    trem5->setVelocidade(value);
    ui->display5->setText(QString::number(value) + " km/h");
}

