#include "status.h"
#include<QColor>
#include<QTime>
#include<QDebug>

void Status::Display(QPainter &paint){

    paint.drawText(30,30,QString("life:")+QString::number(life));
    paint.drawText(30,40,QString("time:")+QString::number(cal(time_Start)/1000)+QString("s"));
}
double Status::cal(double ts){
    double te=(double)clock();
    double time=(te-ts);
    return time;
}
