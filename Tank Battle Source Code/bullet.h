#ifndef BULLET_H
#define BULLET_H

#include"base.h"
#include"tank.h"
class Bullet : public Base
{
public:
    Bullet(const Tank &tank);
    // 绘图
  void Display(QPainter &paint) ;

    // 移动
    void Move() ;
    //
protected:
    void CalculateSphere();
private:
    int style;
    int group;//子弹所在组

};

#endif
