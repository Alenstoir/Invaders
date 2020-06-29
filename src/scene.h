#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "hp.h"


class IScene: public QGraphicsView{
public:
    IScene(QWidget * parent=0);
    int bulletsCollided;

    QMediaPlayer * xplode;
    QMediaPlayer * background;
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Hp * health1;
    Hp * health2;
    Hp * health3;
    void death();
    int getBulletsCollided() const;
    void setBulletsCollided(int value);
    void playXplode();
    void delay();
    void buildWalls(int x, int y);
signals:
    void valueChanged(int noway);

};

#endif // GAME_H
