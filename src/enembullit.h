#ifndef BULLIT_H
#define BULLIT_H
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QObject>

#endif // BULLIT_H
class EnemBullIt: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    EnemBullIt(QGraphicsItem * parent=0);
    QMediaPlayer * xplode;
public slots:
    void move();
};
