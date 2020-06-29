#ifndef MENU
#define MENU

#include <QMediaPlayer>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>

class Menu: public QGraphicsView{
    Q_OBJECT

public:
    Menu(QWidget * parent=0);

    QMediaPlayer * background;
    QGraphicsScene * scene;

public slots:
    void pressedButton();

private:
    QPushButton *button;
};


#endif // MENU
