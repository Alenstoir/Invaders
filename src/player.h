#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMediaPlayer>

#endif // PLAYER_H
class Player: public QGraphicsPixmapItem{
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * keyPressed);
private:
    QMediaPlayer * shotsound;

};
