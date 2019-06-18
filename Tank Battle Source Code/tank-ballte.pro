#-------------------------------------------------
#
# Project created by QtCreator 2018-07-11T14:49:42
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tank-ballte
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tbmainwindow.cpp \
    connectmysql.cpp \
    gradesdialog.cpp \
    mainwindow.cpp \
    base.cpp \
    bullet.cpp \
    gamemap.cpp \
    main.cpp \
    mapcell.cpp \
    status.cpp \
    tank.cpp

HEADERS += \
        tbmainwindow.h \
    connectmysql.h \
    gradesdialog.h \
    mainwindow.h \
    base.h \
    bullet.h \
    gamemap.h \
    main.h \
    mapcell.h \
    status.h \
    tank.h

FORMS += \
        tbmainwindow.ui \
    gradesdialog.ui

RESOURCES += \
    picture.qrc

DISTFILES +=

RC_ICONS = tank.ico

