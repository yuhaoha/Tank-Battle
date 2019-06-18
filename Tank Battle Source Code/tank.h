
#ifndef TANK_H
#define TANK_H
#include"base.h"
#include"main.h"
#include"gamemap.h"
#include"bullet.h"
class Tank : public Base
{
protected:
    QList<Bullet*> bullets;
   int  group;//坦克所在组
   // 计算势力范围
   virtual void CalculateSphere();
public:
   Status *status;
   friend class Bullet;
    Tank();//wanjia player
    Tank(int iIndex,int jIndex,Dir dir=UP,int group=1);//element player
    // 绘图
    void Display(QPainter &paint);

    // 移动
    void Move();
    //
    void Move1();//fangzhi si xun huan
    //设置移动状态为开
    void startmove(){ismove=true;}
    //设置移动状态为关
    void stopmove(){ismove=false;}
    //
    void fire();
    void startfire();
    void stopfire();
    //设置方向
    void setdir(Dir dir){m_dir=dir;}
    //坦克下一步 是否和地图块碰撞
   bool nextsiboom();


private:
    bool ismove;
    bool isfire;
    int gongjijiange;
    int style;
};

#endif // TANK_H
