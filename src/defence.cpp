#include "defence.h"


Wall::Wall(int type, int rotate):QObject(), QGraphicsPixmapItem(){
    if(type == 0){
        setPixmap(QPixmap(":/images/horrizwalls.png"));
        if(rotate == 1){
            setTransformOriginPoint(10,5);
            setRotation(90);
        } else if(rotate == 2){
            setTransformOriginPoint(10,5);
            setRotation(-90);
        }
    } else if(type == 1){
        setPixmap(QPixmap(":/images/cornerwalls.png"));
        if(rotate == 1){
            setTransformOriginPoint(5,5);
            setRotation(90);
        }
    }
}

int Wall::getWallHp() const
{
    return wallHp;
}

void Wall::setWallHp(int value)
{
    wallHp = value;
}


