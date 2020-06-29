#ifndef BULLIT_H
#define BULLIT_H
#include <QGraphicsPixmapItem>
#include <QObject>

#endif // BULLIT_H
class BullIt: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BullIt(QGraphicsItem * parent=0);
public slots:
    void move();
};
