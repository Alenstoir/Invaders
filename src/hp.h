#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>

class Hp: public QGraphicsPixmapItem{
public:
    Hp(QGraphicsItem * parent=0);
    void hpChange(int hp);
    int getHp();
private:
    int health=1;
};

#endif // HEALTH_H
