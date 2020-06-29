#include "menu.h"
#include "scene.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
#include <typeinfo>
#include <QCoreApplication>

IScene * iscene;

Menu::Menu(QWidget *parent)
{
    // экран
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setBackgroundBrush(QBrush(Qt::black));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    button = new QPushButton("Start", this);
    button->setGeometry(QRect(QPoint(300, 300), QSize(200, 50)));
    connect(button, SIGNAL (released()), this, SLOT (pressedButton()));
}

void Menu::pressedButton()
{
    iscene = new IScene();
    iscene->show();
    delete this;
}

