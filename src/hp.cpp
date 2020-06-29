#include "hp.h"

Hp::Hp(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/fullheart.png"));

}

void Hp::hpChange(int hp)
{
    health=hp;
    if(health==0){
        setPixmap(QPixmap(":/images/voidheart.png"));
    }
}

int Hp::getHp()
{
    return(health);
}

