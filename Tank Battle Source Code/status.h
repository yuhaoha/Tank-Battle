#ifndef STATUS_H
#define STATUS_H

#include"base.h"
#include<sys/time.h>
class Status
{
public:
    double time_Start;
    float life;
    Status(){
        life=1;
        time_Start=(double)clock();
    }
    double cal(double ts);
    void Display(QPainter &paint);
};

#endif // STATUS_H
