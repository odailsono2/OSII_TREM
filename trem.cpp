#include "trem.h"
#include <QtCore>

#define X_TRILHO1 240
#define Y_TRILHO1 80
#define TRILHO_H_COMP 270
#define TRILHO_V_COMP 120
#define TRILHO_ESP 20
#define TREM_WIDTH 21
#define TREM_HEIGTH 17

#define X_TRILHO2 90
#define Y_TRILHO2 200

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}
void Trem::setVelocidade(int valor){
    this->velocidade = valor*10 ;
}
//Função a ser executada após executar trem->START
void Trem::run(){

    int parar = 1;



    while(true){

        if (velocidade == 0)
            parar = 0;
        else
            parar = 1;


        switch(ID){
        case 1:     //Trem 1
            if (x < X_TRILHO1 + TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10*parar;
            else if (x == X_TRILHO1 + TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO1  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (x < X_TRILHO1 + 2*TRILHO_H_COMP && y == Y_TRILHO1)
                x+=10*parar;
            else if (x == X_TRILHO1 + 2*TRILHO_H_COMP && y < Y_TRILHO1 + TRILHO_V_COMP)
                y+=10*parar;
            else if (x > X_TRILHO1 + TRILHO_H_COMP  && y == Y_TRILHO1 + TRILHO_V_COMP)
                x-=10*parar;
            else
                y-=10*parar;
            emit updateGUI(ID, x,y);    //Emite um sinal
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
            emit updateGUI(ID, x,y);    //Emite um sinal
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
            emit updateGUI(ID, x,y);    //Emite um sinal
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
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        default:
            break;
        }
        msleep(550-velocidade);

    }
}




