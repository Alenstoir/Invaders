#ifndef DEFENCE_H
#define DEFENCE_H
#include <QGraphicsPixmapItem>
#include <QObject>

#endif // DEFENCE_H

class Wall: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wall(int type, int rotate);
    int getWallHp() const;
    void setWallHp(int value);
private:
    int wallHp;

};

