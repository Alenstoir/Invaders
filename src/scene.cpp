#include "scene.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QImage>
#include <QTime>
#include <QCoreApplication>
#include "defence.h"
#include <typeinfo>
#include <QList>

IScene::IScene(QWidget *parent){
    // экран
    bulletsCollided=0;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setBackgroundBrush(QBrush(Qt::black));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    // звуки
    xplode = new QMediaPlayer();
    xplode->setMedia(QUrl("qrc:/sound/explode.mp3"));
    // защитник
    player = new Player();
    player->setPixmap(QPixmap(":/images/defender.png"));
    player->setPos(375,525);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);
    // очки
    score = new Score();
    scene->addItem(score);
    //хп
    health1 = new Hp();
    health1->setPos(health1->x()+5,health1->y()+30);
    scene->addItem(health1);

    health2 = new Hp();
    health2->setPos(health2->x()+20,health2->y()+30);
    scene->addItem(health2);

    health3 = new Hp();
    health3->setPos(health3->x()+35,health3->y()+30);
    scene->addItem(health3);
    // структуры
    buildWalls(75,475);
    buildWalls(225,475);
    buildWalls(375,475);
    buildWalls(525,475);
    buildWalls(675,475);
    // враги
    for(int i = 1;i < 11; i++){
            Enemy * enemy = new Enemy();
            enemy->setPos(20+(65*i),50);
            scene->addItem(enemy);
            //connect(this->bulletsCollided,SIGNAL(valueChanged(int)),enemy,SLOT(speedup(int)));
    }
    for(int i = 1;i < 11; i++){
            Enemy * enemy = new Enemy();
            enemy->setPos(20+(65*i),100);
            scene->addItem(enemy);

    }
    for(int i = 1;i < 11; i++){
            Enemy * enemy = new Enemy();
            enemy->setPos(20+(65*i),150);
            scene->addItem(enemy);

    }
    background = new QMediaPlayer();
    background->setMedia(QUrl("qrc:/sound/bg.mp3"));
    background->play();


//    Enemy *enemy = new Enemy();
//    //scene->addItem(enemy);
//    show();
}

void IScene::death()
{
    background->stop();
    background->setMedia(QUrl("qrc:/sound/gameover.wav"));
    background->play();
    QGraphicsPixmapItem *deathscreen = new QGraphicsPixmapItem();
    deathscreen->setPixmap(QPixmap(":/images/gameover.png"));
    deathscreen->setPos(200,200);
    scene->addItem(deathscreen);
    delay();
    delete this;
}

int IScene::getBulletsCollided() const
{
    return bulletsCollided;
}

void IScene::setBulletsCollided(int value)
{
    bulletsCollided = value;
}

void IScene::playXplode()
{
    if(xplode->state() == QMediaPlayer::PlayingState){
        xplode->setPosition(0);
    }
    else if(xplode->state() == QMediaPlayer::StoppedState){
        xplode->play();
    }
}

void IScene::delay()
{
        QTime dieTime= QTime::currentTime().addSecs(3);
        while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void IScene::buildWalls(int x, int y)
{
    Wall *def00 = new Wall(0,2);
    Wall *def01 = new Wall(1,0);
    Wall *def02 = new Wall(0,0);
    Wall *def03 = new Wall(1,1);
    Wall *def04 = new Wall(0,1);
    def00->setPos(x,y);
    def01->setPos(x+5,y-15);
    def02->setPos(x+15,y-15);
    def03->setPos(x+35,y-15);
    def04->setPos(x+30,y);
    scene->addItem(def00);
    scene->addItem(def01);
    scene->addItem(def02);
    scene->addItem(def03);
    scene->addItem(def04);
}
