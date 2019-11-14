#include "rectangulo.h"
#include "rectangulo.cpp"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGenericMatrix>
#include <iostream>
#include <QGraphicsRectItem>

using namespace std;
/*
Tutorial Topics:
-QTimer
-signals and slots (connect function)
-QObject and Q_OBJECT macro
*/

int main(int argc, char *argv[]){
    srand(time(NULL));
    QApplication a(argc, argv);
    // create a scene
    int matriz[100][100];
    int num;
    QGraphicsScene * scene = new QGraphicsScene();
    for (int i=0;i<100;i++){
        for(int j=0;j<100;j++){
          num= rand()%100;
          cout << num;
          if (num==1){
              matriz[i][j]=num;
              QGraphicsRectItem *d = new QGraphicsRectItem(i*5,j*5,5,5);
              d->setBrush(Qt::red);
              scene->addItem(d);
          }else{ matriz[i][j]=0;}

        }
    }
    // create an item to add to the scene
    rectangulo *rect=new rectangulo();
    rect->setRect(0,0,5,5); // change the rect from 0x0 (default) to 100x100 pixels
    rect->setBrush(Qt::blue);
    // add the item to the scene
    scene->addItem(rect);
    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // show the view
    view->show();
    rect->buscardestino(matriz,0,0,50,50);
    //==new code==


    return a.exec();
}
