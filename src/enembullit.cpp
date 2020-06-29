#include "enemy.h"
#include <typeinfo>
#include "scene.h"
#include <QDebug>
#include "enembullit.h"
#include <QTimer>
#include "defence.h"


extern IScene * iscene;

EnemBullIt::EnemBullIt(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/enembullit.png"));
    setPos(x()-11.5,y());
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void EnemBullIt::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(this);
            delete this;
            if(iscene->health3->getHp()==1){
                iscene->health3->hpChange(0);
                iscene->playXplode();
            }
            else if(iscene->health2->getHp()==1){
                iscene->health2->hpChange(0);
                iscene->playXplode();
            }
            else if(iscene->health1->getHp()==1){
                iscene->health1->hpChange(0);
                iscene->playXplode();
                iscene->death();
            }
            return;
        } else if(typeid(*(colliding_items[i])) == typeid(Wall)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    setPos(x(),y()+10);
    if(pos().y() + pixmap().height() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
