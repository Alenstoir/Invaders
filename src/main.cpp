#include <QApplication>
#include "scene.h"
#include "menu.h"

Menu * menuscene;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    menuscene = new Menu();
    menuscene->show();

    return a.exec();
}
