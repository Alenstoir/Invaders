#include "player.h"
#include <QKeyEvent>
#include "bullit.h"
#include <QGraphicsScene>
#include <QMediaPlayer>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    shotsound = new QMediaPlayer();
    shotsound->setMedia(QUrl("qrc:/sound/shoot.wav"));
}

void Player::keyPressEvent(QKeyEvent *keyPressed)
{
    if(keyPressed->key() == Qt::Key_A or keyPressed->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-5,y());
        }
    }
    else if(keyPressed->key() == Qt::Key_Right|| keyPressed->key() == Qt::Key_D){
        if(pos().x() + 50 < 800){
            setPos(x()+5,y());
        }
    }
//    else if(keyPressed->key() == Qt::Key_Up){
//        setPos(x(),y()-5);
//    }
//    else if(keyPressed->key() == Qt::Key_Down){
//        setPos(x(),y()+5);
//    }
    if(keyPressed->key() == Qt::Key_Space){
        BullIt * bullet = new BullIt();
        bullet->setPos(x()+23,y());
        scene()->addItem(bullet);
        if(shotsound->state() == QMediaPlayer::PlayingState){
            shotsound->setPosition(0);
        }
        else if(shotsound->state() == QMediaPlayer::StoppedState){
            shotsound->play();
        }
    }
}

