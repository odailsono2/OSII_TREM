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


QMutex mtx1;//(QMutex::Recursive);
QMutex mtx2;
QMutex mtx3;
QMutex mtx4;
QMutex mtx5;
QMutex mtx6;
QMutex mtx7;


void trava(Trem* trem, int m1, int m2, int m3,int m4,int m5, int m6, int m7){
    QString msg;



    msg.append("Trem " + QString::number(trem->getID()) );
    int comp = msg.size();
    if (m1){
        mtx1.lock();
        trem->regiao_critica[0] = true;
        msg.append(" mtx 1 on |");
    }
    if (m2){
        mtx2.lock();
        trem->regiao_critica[1] = true;
        msg.append(" mtx 2 on |");
    }
    if (m3){
        mtx3.lock();
        trem->regiao_critica[2] = true;
        msg.append(" mtx 3 on |");
    }
    if (m4){
        mtx4.lock();
        trem->regiao_critica[3] = true;
        msg.append(" mtx 4 on |");
    }
    if (m5){
        mtx5.lock();
        trem->regiao_critica[4] = true;
        msg.append(" mtx 5 on |");
    }
    if (m6){
        mtx6.lock();
        trem->regiao_critica[5] = true;
        msg.append(" mtx 6 on |");
    }
    if (m7){
        mtx7.lock();
        trem->regiao_critica[6] = true;
        msg.append(" mtx 7 on |");
    }
    if (msg.size() != comp)
        qDebug()<<msg;
}

void destrava(Trem* trem, int m1, int m2, int m3,int m4,int m5, int m6, int m7){
    QString msg;

    msg.append("Trem " + QString::number(trem->getID()) );

    int comp = msg.size();

    if (m1){
        mtx1.unlock();
        trem->regiao_critica[0] = false;
        msg.append(" mtx 1 off |");
    }
    if (m2){
        mtx2.unlock();
        trem->regiao_critica[1] = false;
        msg.append(" mtx 2 off |");
    }
    if (m3){
        mtx3.unlock();
        trem->regiao_critica[2] = false;
        msg.append(" mtx 3 off |");
    }
    if (m4){
        mtx4.unlock();
        trem->regiao_critica[3] = false;
        msg.append(" mtx 4 off |");
    }
    if (m5){
        mtx5.unlock();
        trem->regiao_critica[4] = false;
        msg.append(" mtx 5 off |");
    }
    if (m6){
        mtx6.unlock();
        trem->regiao_critica[5] = false;
        msg.append(" mtx 6 off |");
    }
    if (m7){
        mtx7.unlock();
        trem->regiao_critica[6] = false;
        msg.append(" mtx 7 off |");
    }

    if (msg.size() != comp)
        qDebug()<<msg;
}

void pontos_checagem(Trem* trem, int ID, int pt, int m[7] , int um[7]){

    //int ID = trem->getID();

    int x = trem->getX();

    int y = trem->getY();

    QString msg;

    msg.append("Trem " + QString::number(trem->getID()) + " ");
    int comp = msg.size();

    if ( x == 490 && y == 80 && pt == 1){ // ponto 1
        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    else if ( x == 490 && y == 200 && pt == 2){ //ponto 2

        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }

    }

    else if ( x == 380  && y == 200 && pt == 3){ //ponto 3

        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }




    }


    else if ( x == 340  && y == 200 && pt == 4){ //ponto 4

        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 3){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }



    }

    else if ( x == 240 && y == 180 && pt == 5){ //ponto 5
        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    else if ( x == 220  && y == 200 && pt == 6){ //ponto 6
        if ( ID == 3){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    else if ( x == 360  &&  y ==220 && pt == 7){ //ponto 7


        if ( ID == 3){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }
    }
    else if ( x == 340  &&  y ==320 && pt == 8){ // ponto 8
        if ( ID == 3){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    else if ( x == 380  &&  y ==320 && pt == 9){ // ponto 9
        if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    if ( x == 530  &&  y ==200 && pt == 10){ // ponto 10

        if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }
    }

    else if ( x == 610  &&  y ==200 && pt == 11){ // ponto 11

        if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }

    }

    else if ( x == 610  &&  y == 320 && pt == 12){ // ponto 12
        if (ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }
    }

    else if ( x == 650  &&  y == 200 && pt==13){ // ponto 13

        if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 5){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }
    }

    else if ( x == 800  &&  y == 200 && pt == 14){ // ponto 14



        if ( ID == 5){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }
    }

    else if ( x == 650  &&  y == 320 && pt == 15){ // ponto 15



        if ( ID == 5){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);
        }

    }
    else if ( x == 510  &&  y == 180 && pt == 16){ // ponto 16

        if ( ID == 1){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }
    }

    else if ( x == 630  &&  y == 220 && pt == 17){ // ponto 17

        if ( ID == 4){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

        else if ( ID == 5){
            msg.append("chegou no ponto "+QString::number(pt));
           trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
           destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);

        }

    }
    else if ( x == 530  &&  y == 80 && pt == 18){ // ponto 18

        if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

    }

    else if ( x == 780  &&  y == 180 && pt == 19){ // ponto 19


        if ( ID == 2){
            msg.append("chegou no ponto "+QString::number(pt));
            trava(trem, m[0], m[1], m[2],m[3], m[4], m[5], m[6]);
            destrava(trem, um[0], um[1], um[2],um[3], um[4], um[5], um[6]);


        }

    }
    if (msg.size() != comp)
        qDebug()<<msg;
}


//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    Thread_parada=false;
}
int Trem::getX(){
    return x;
}

int Trem::getY(){
    return y;
}
int Trem::getID(){
    return ID;
}
void Trem::setVelocidade(int valor){
    this->velocidade = valor ;

    if (velocidade == 0 ){
        stopThread();
        qDebug()<<"velocidade 0";
    }
    else
        Thread_parada= false;
        start();
}

void Trem::stopThread(){
    this->Thread_parada.store(true);
}
void Trem::startThread(){
    this->Thread_parada.store(false);
}

//Função a ser executada após executar trem->START
void Trem::run(){

    while(true){
        if(Thread_parada){
            break;
            //qDebug() << "Parada";
        }

        // trem 1
        if (ID == 1){
            {// ponto 1
                int mtx[7]  = {1,1,1,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 1;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

            {// ponto 16
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 16;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 2
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {1,0,0,0,0,0,0};
                int pt = 2;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 3
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 3;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 4
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,1,0,0,1,0};
                int pt = 4;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 5
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,1,0,0,0,0,0};
                int pt = 5;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
        }
        //--------------------

        // trem 2
        if (ID == 2){
            {// ponto 19
                int mtx[7]  = {1,0,0,1,1,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 19;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

            {// ponto 13
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 13;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 11
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,1,0,0};
                int pt = 11;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 10
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 10;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 16
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,1,0,0,0};
                int pt = 16;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 18
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {1,0,0,0,0,0,0};
                int pt = 18;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
        }
        //--------------------

        // trem 3
        if (ID == 3){
            {// ponto 6
                int mtx[7]  = {0,1,0,0,0,1,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 6;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

            {// ponto 4
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 4;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 7
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,1,0,0,0,0,0};
                int pt = 7;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 8
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,1,0};
                int pt = 8;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

        }
        //--------------------
        // trem 4
        if (ID == 4){
            {// ponto 9
                int mtx[7]  = {0,0,1,1,0,1,1};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 9;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

            {// ponto 7
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 7;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 3
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,1,0};
                int pt = 3;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 2
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 2;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 10
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,1,0,0,0,0};
                int pt = 10;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 11
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 11;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 17
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,1,0,0,0};
                int pt = 17;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 12
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,1};
                int pt = 12;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
        }
        //--------------------

        // trem 5
        if (ID == 5){
            {// ponto 15
                int mtx[7]  = {0,0,0,0,1,0,1};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 15;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

            {// ponto 17
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,0};
                int pt = 17;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 13
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,0,0,1};
                int pt = 13;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }
            {// ponto 14
                int mtx[7] =  {0,0,0,0,0,0,0};
                int umtx[7] = {0,0,0,0,1,0,0};
                int pt = 14;
                pontos_checagem(this,ID,pt,mtx,umtx);
            }

        }
        //--------------------

//        if (velocidade == 0){
//            this->quit();
//            this->wait();
//        }else
//            this->start();


        switch(ID){

        case 1:     //Trem 1
            if (x < X_TRILHO1 + TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10;
            else if (x == X_TRILHO1 + TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP){
                y+=10;//move_vertical(y,10,parar,regiao_critica);

            }
            else if (x > X_TRILHO1  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10;
            else
                y-=10;

            break;
        case 2: //Trem 2
            if (x < X_TRILHO1 + 2*TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10;
            else if (x == X_TRILHO1 + 2*TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP)
                y+=10;
            else if (x > X_TRILHO1 + TRILHO_H_COMP  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10;
            else{
                y+=-10;//move_vertical(y,-10,parar,regiao_critica);
            }

            break;
        case 3: //Trem 3
            if (x < X_TRILHO2 + TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10;
            else if (x == X_TRILHO2 + TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10;
            else if (x > X_TRILHO2  && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10;
            else
                y-=10;

            break;
        case 4: //Trem 4
            if (x < X_TRILHO2 + 2*TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10;
            else if (x == X_TRILHO2 + 2*TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10;
            else if (x > X_TRILHO2 + TRILHO_H_COMP && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10;
            else
                y-=10;

            break;
        case 5: //Trem 5
            if (x < X_TRILHO2 + 3*TRILHO_H_COMP && y == Y_TRILHO2)
                x+=10;
            else if (x == X_TRILHO2 + 3*TRILHO_H_COMP && y < Y_TRILHO2 + TRILHO_V_COMP)
                y+=10;
            else if (x > X_TRILHO2 + 2*TRILHO_H_COMP && y == Y_TRILHO2 + TRILHO_V_COMP)
                x-=10;
            else
                y-=10;

            break;

        default:
            break;
        }



        //qDebug()<<"Trem ID = "<<ID <<" saiu";

        emit updateGUI(ID, x,y);    //Emite um sinal

        msleep(210-velocidade);



   }
}

//void Trem::run(){


