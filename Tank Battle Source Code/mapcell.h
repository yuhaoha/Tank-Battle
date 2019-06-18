#ifndef MAPCELL_H
#define MAPCELL_H

#include"base.h"
#include"main.h"
#include<fstream>
class Mapcell : public Base
{
public:
        enum {BLOCKSNUM=13};
        static float lifes[BLOCKSNUM];
        static float hujias[BLOCKSNUM];
        static float mokangs[BLOCKSNUM];
        static bool chuantous[BLOCKSNUM];
        static bool chuantous1[BLOCKSNUM];
    Mapcell();
    Mapcell(int iIndex, int jIndex, int style=0);//护甲魔抗物理攻击魔法攻击攻击速度移动速度暂时用不到
    // 绘图
    void Display(QPainter &paint);

    // 移动
   void Move();
   //得到方块样式
   int getstyle(){return style;}
   //切换样式
   int switchstyle(){style++;style=style%BLOCKSNUM; this->life=lifes[this->style];
                     this->chuantou=chuantous[this->style];
                     this->chuantou1=chuantous1[this->style];return style;}
   //设置样式
   void setstyle(int style){this->style=style%BLOCKSNUM; this->life=lifes[this->style];

                            this->chuantou=chuantous[this->style];
                            this->chuantou1=chuantous1[this->style];}
   //
   bool ischuantou(){return chuantou;}
   //
   bool ischuantou1(){return chuantou1;}
private:
//static QImage blockimage;
   int style;//方块样式，从图片上依次编号0 ，1，2 ，3，4，5.。。。。
   //
   void cal(int style,int &i,int &j){//将一维编号变成一行有4列的二维编号i行j列
     i=style/4;
    j=style%4;
   }
void CalculateSphere(){
    this->m_rectSphere.setRect(m_pos.x()-CELLWIDTH/2,m_pos.y()-CELLHEIGHT/2,CELLWIDTH,CELLHEIGHT);

}

bool chuantou;//坦克能否穿透方块
bool chuantou1;//子弹能否穿透方块

};

#endif // MAPCELL_H
