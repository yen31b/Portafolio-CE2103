#include "rectangulo.h"

#include <QCoreApplication>
#include <QGraphicsScene>
#include <QTime>





void rectangulo::buscardestino(int matriz[100][100], int xi, int yi, int xf, int yf)
{
    int i=xi,j=yi;
    int random;
    while (i!=xf && j!=yf){
        if (i!=xf){
            if (matriz[i][j]==1){
                while (matriz[i][j]==1){
                    random=rand()%4;
                    if (random==0 && matriz[i+1][j]!=1){
                        i++;
                        this->setX(i*5);}
                    else if (random==1 && matriz[i-1][j]!=1){
                        i--;
                        this->setX(i*5);}
                    else if (random==2 && matriz[i][j+1]!=1){
                        j--;
                        this->setY(j*5);}
                    else if(matriz[i][j-1]!=1) {
                        j--;
                        this->setY(j*5);}
                }
            }
            else{
                this->setX(i*5);
                if (i<xf){i++;}
                else{i--;}
            }
        }
        this->delay();
        if (j!=xf){
            if (matriz[i][j]==1){
                while (matriz[i][j]==1){
                    random=rand()%4;
                    if (random==0 && matriz[i+1][j]!=1){
                        i++;
                        this->setX(i*5);}
                    else if (random==1 && matriz[i-1][j]!=1){
                        i--;
                        this->setX(i*5);}
                    else if (random==2 && matriz[i][j+1]!=1){
                        j--;
                        this->setY(j*5);}
                    else if(matriz[i][j-1]!=1) {
                        j--;
                        this->setY(j*5);}
                }
            }
            else{
                this->setY(j*5);
                if (j<yf){j++;}
                else{j--;}
            }
    }
        this->delay();
  }
}

void rectangulo::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(300);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}




