#include "main.h"
#include "mainwindow.h"
#include "tbmainwindow.h"
#include "connectmysql.h"
#include <QApplication>
Glo glo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ConnectMysql cm;
//    cm.connect();
    TBMainWindow w;
    w.show();
    return a.exec();
}


