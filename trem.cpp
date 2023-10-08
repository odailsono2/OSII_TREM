#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>
#include <QDebug>

#define X_TRILHO1 240
#define Y_TRILHO1 80
#define TRILHO_H_COMP 270
#define TRILHO_V_COMP 120
#define TRILHO_ESP 20
#define TREM_WIDTH 21
#define TREM_HEIGTH 17

#define X_TRILHO2 90
#define Y_TRILHO2 200

int ID_trava1 = 0;
int ID_trava2 = 0;
int ID_trava3 = 0;
int ID_trava4 = 0;
int ID_trava5 = 0;
int ID_trava6 = 0;
int ID_trava7 = 0;

QMutex mtx1;//(QMutex::Recursive);
QMutex mtx2;
QMutex mtx3;
QMutex mtx4;
QMutex mtx5;
QMutex mtx6;
QMutex mtx7;


QSemaphore sem1(1);
QSemaphore sem2(1);
QSemaphore sem3(1);
QSemaphore sem4(1);
QSemaphore sem5(1);
QSemaphore sem6(1);
QSemaphore sem7(1);

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}
int Trem::getX(){
    return x;
}

int Trem::getY(){
    return y;
}

void Trem::setVelocidade(int valor){
    this->velocidade = valor*10 ;
}

void move_vertical(int&y, const int &passo, const int& parar, const bool& ok){

//    if (ok){
       //sem1.acquire();
   //    mtx1.lock();

//    }

    y+=passo*parar;

//    if (!ok){
//      // sem1.acquire();
//       mtx1.unlock();
//    }


}
//Função a ser executada após executar trem->START
void Trem::run(){

    int parar = 1;




    while(true){

        //-------Regiao Critica 1
        if ( x == 510 && y >= 90 && y <= 190){

            regiao_critica [0] = true;

            if ( ID != ID_trava1){
                //sem1.acquire();
                mtx1.lock();

                ID_trava1 = ID;

                qDebug()<<"Trem ID = "<<ID_trava1 <<"travou mtx1";
            }
        }else{

            regiao_critica [0] = false;

        }
        //---------Fim da regiao critica 1

        //---------Regiao Critica 2
        if ( x >= 250  && x <= 350  && y == 200 ){

            regiao_critica [1] = true;

            if ( ID != ID_trava2){
                //sem1.acquire();
                mtx2.lock();

                ID_trava2 = ID;

                qDebug()<<"Trem ID = "<<ID_trava2 <<"travou mtx2";
            }
        }else{

            regiao_critica [1] = false;

        }

        //---------Regiao Critica 3
        if ( x >= 370  && x <= 380 + 111  && y == 200 ){

            regiao_critica [2] = true;

            if ( ID != ID_trava3){
                //sem1.acquire();
                mtx3.lock();

                ID_trava3 = ID;

                qDebug()<<"Trem ID = "<<ID_trava3 <<"travou mtx3";
            }
        }else{

            regiao_critica [2] = false;

        }

        //---------Regiao Critica 4
        if ( x >= 520 && x <= 530+91  && y == 200 ){

            regiao_critica [3] = true;

            if ( ID != ID_trava4){
                //sem1.acquire();
                mtx4.lock();

                ID_trava4 = ID;

                qDebug()<<"Trem ID = "<<ID_trava4 <<"travou mtx4";
            }
        }else{

            regiao_critica [3] = false;

        }

        //---------Regiao Critica 5
        if ( x >= 655 && x <= 650+121  && std::abs( y - (Y_TRILHO1 + TRILHO_V_COMP)) == 0 ){

            regiao_critica [4] = true;

            if ( ID != ID_trava5){
                //sem1.acquire();
                mtx5.lock();

                ID_trava5 = ID;

                qDebug()<<"Trem ID = "<<ID_trava5 <<"travou mtx5";
            }
        }else{

            regiao_critica [4] = false;

        }

        //---------Regiao Critica 6
        if ( x == 360  &&  y >=210 && y <= 220 + 90 ){

            regiao_critica [5] = true;

            if ( ID != ID_trava6){
                //sem1.acquire();
                mtx6.lock();

                ID_trava6 = ID;

                qDebug()<<"Trem ID = "<<ID_trava6 <<"travou mtx6";
            }
        }else{

            regiao_critica [5] = false;

        }

        if ( x == 630  &&  y >= 210 && y <= 220+90 ){

            regiao_critica [6] = true;

            if ( ID != ID_trava7){
                //sem1.acquire();
                mtx7.lock();

                ID_trava7 = ID;

                qDebug()<<"Trem ID = "<<ID_trava7 <<"travou mtx2";
            }
        }else{

            regiao_critica [6] = false;

        }
        if (velocidade == 0)
            parar = 0;
        else
            parar = 1;

        if(ID==3){
            qDebug()<<"Trem ID = "<<ID <<" entrou no loop";
            qDebug()<<"(x,y) "<<"("<<x<<","<<y<<")"<<" | Velocidade " << velocidade<< " Regiao Critica [0] "<<regiao_critica[0];
            qDebug()<<"     |x-trilhoX| = "<<std::abs(x - (X_TRILHO1 + TRILHO_H_COMP ));
        }

        switch(ID){

        case 1:     //Trem 1
            if (x < X_TRILHO1 + TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10*parar;
            else if (x == X_TRILHO1 + TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP){
                y+=10*parar;//move_vertical(y,10,parar,regiao_critica);

            }
            else if (x > X_TRILHO1  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;

            break;
        case 2: //Trem 2
            if (x < X_TRILHO1 + 2*TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10*parar;
            else if (x == X_TRILHO1 + 2*TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO1 + TRILHO_H_COMP  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10*parar;
            else{
                y+=-10*parar;//move_vertical(y,-10,parar,regiao_critica);
            }

            break;
        case 3: //Trem 3
            if (x < X_TRILHO2 + TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10*parar;
            else if (x == X_TRILHO2 + TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO2  && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;

            break;
        case 4: //Trem 4
            if (x < X_TRILHO2 + 2*TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10*parar;
            else if (x == X_TRILHO2 + 2*TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO2 + TRILHO_H_COMP && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;

            break;
        case 5: //Trem 5
            if (x < X_TRILHO2 + 3*TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10*parar;
            else if (x == X_TRILHO2 + 3*TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO2 + 2*TRILHO_H_COMP && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;

            break;

        default:
            break;
        }



        //qDebug()<<"Trem ID = "<<ID <<" saiu";

        emit updateGUI(ID, x,y);    //Emite um sinal

        msleep(550-velocidade);

        if (ID == ID_trava1 && !regiao_critica[0]){
            //
            mtx1.unlock();
            //sem1.release();
            ID_trava1 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx1";
        }

        if (ID == ID_trava2 && !regiao_critica[1]){
            //
            mtx2.unlock();
            //sem1.release();
            ID_trava2 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx2";
        }

        if (ID == ID_trava3 && !regiao_critica[2]){
            //
            mtx3.unlock();
            //sem1.release();
            ID_trava3 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx3";
        }

        if (ID == ID_trava4 && !regiao_critica[3]){
            //
            mtx4.unlock();
            //sem1.release();
            ID_trava4 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx4";
        }

        if (ID == ID_trava5 && !regiao_critica[4]){
            //
            mtx5.unlock();
            //sem1.release();
            ID_trava5 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx5";
        }

        if (ID == ID_trava6 && !regiao_critica[5]){
            //
            mtx6.unlock();
            //sem1.release();
            ID_trava6 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx6";
        }

        if (ID == ID_trava7 && !regiao_critica[6]){
            //
            mtx7.unlock();
            //sem1.release();
            ID_trava7 = 0;
            qDebug()<<"Trem ID = "<<ID <<"liberou mtx7";
        }

    }

}




