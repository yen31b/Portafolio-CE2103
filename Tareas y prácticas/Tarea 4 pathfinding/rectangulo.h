#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <QGraphicsRectItem>
class rectangulo: public QGraphicsRectItem{

public:
   void buscardestino(int matriz[100][100], int xi,int yi, int xf,int yf);
   void delay();
};

#endif // RECTANGULO_H
