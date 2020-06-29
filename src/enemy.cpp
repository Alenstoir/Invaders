#include "enemy.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h>
#include <QGraphicsScene>
#include "enembullit.h"
#include "scene.h"
#include "defence.h"
#include <typeinfo>

extern IScene * iscene;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    setPixmap(QPixmap(":/images/invaider.png"));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timervalue = (400 - pos().y())/2;
    timer->start(timervalue);

    int random_num = ((rand() % 5000)+4500);
    QTimer * stimer = new QTimer();
    connect(stimer,SIGNAL(timeout()),this,SLOT(shoot()));
    stimer->start(random_num);

    QTimer * speedy = new QTimer();
    connect(speedy,SIGNAL(timeout()),this,SLOT(speedup()));
    speedy->start(25);
}

void Enemy::move(){
    int cnt=getCnt();
    int cntX=getCntX();
    if((cnt % 2) == 0){
        if(cntX < 6){
            setPos(x()+5,y());
            setCntX(cntX+1);
        }
        else {
            setPos(x(),y()+25);
            setCnt(cnt+1);
            setCntX(0);

        }
    }
    else if((cnt % 2) != 0){
        if(cntX < 6){
            setPos(x()-5,y());
            setCntX(cntX+1);
        }
        else {
            setPos(x(),y()+25);
            setCnt(cnt+1);
            setCntX(0);

        }
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i<n; i++){
            if(typeid(*(colliding_items[i])) == typeid(Wall)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    if(pos().y() > 600){
        iscene->death();
    }
}

void Enemy::shoot()
{
    EnemBullIt * bullet = new EnemBullIt();
    bullet->setPos(x()+11.5,y()+5);
    scene()->addItem(bullet);
}

void Enemy::speedup()
{
    if(iscene->getBulletsCollided() != speed){
        timer->stop();
        setTimervalue(getTimervalue()-7.5);
        timer->start(timervalue);
        speed = iscene->getBulletsCollided();
    }
}
int Enemy::getCnt() const
{
    return cnt;
}

void Enemy::setCnt(int value)
{
    cnt = value;
}

int Enemy::getCntX() const
{
    return cntX;
}

void Enemy::setCntX(int value)
{
    cntX = value;
}

int Enemy::getTimervalue() const
{
    return timervalue;
}

void Enemy::setTimervalue(int value)
{
    timervalue = value;
}
