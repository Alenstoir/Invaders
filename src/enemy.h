#ifndef ENEMY_H
#define ENEMY_H

#endif // ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    int cnt = 2;
    int cntX = 0;
    Enemy();
    int speed = 0;

    int getCnt() const;
    void setCnt(int value);

    int getCntX() const;
    void setCntX(int value);

    int getTimervalue() const;
    void setTimervalue(int value);

private:
    QTimer *timer;
    int timervalue;

public slots:
    void move();
    void shoot();
    void speedup();


};
