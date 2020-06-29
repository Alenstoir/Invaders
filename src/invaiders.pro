#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T10:02:16
#
#-------------------------------------------------

QT       += core gui \
            multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = invaiders
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    scene.cpp \
    bullit.cpp \
    enemy.cpp \
    score.cpp \
    hp.cpp \
    enembullit.cpp \
    defence.cpp \
    menu.cpp

HEADERS  += \
    player.h \
    scene.h \
    bullit.h \
    enemy.h \
    score.h \
    hp.h \
    enembullit.h \
    defence.h \
    menu.h

RESOURCES += \
    res.qrc
