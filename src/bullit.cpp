#include "bullit.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "scene.h"
#include <QDebug>
#include "defence.h"

extern IScene * iscene;


BullIt::BullIt(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/bullit.png"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void BullIt::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            iscene->score->increase();
            iscene->setBulletsCollided(iscene->getBulletsCollided()+1);

            return;
        } else if(typeid(*(colliding_items[i])) == typeid(Wall)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
