#ifndef BASE_H
#define BASE_H
#include<QPoint>
#include<QRect>
#include<QPainter>
#include<QImage>
#include"main.h"
enum Dir { UP, DOWN, LEFT, RIGHT };
class Base
{
 protected:
    // 计算势力范围
    virtual void CalculateSphere() = 0;

    // 位置
    QPoint m_pos;
    // 势力范围
    QRect m_rectSphere;
    // 颜色
    //QColor m_color;
    // 方向
    Dir m_dir;
    // 存在状态
    bool m_bDisappear;
    // 单次前进步长
    int m_step;
    //生命值
    //物理攻击
    float wuli;

 public:
    float life;
    friend class Status;
       // 绘图
       virtual void Display(QPainter &paint) = 0;

       // 移动
       virtual void Move() = 0;

       // 判断是否消失
       bool IsDisappear(){return m_bDisappear;}

       //判断两物体是否碰撞
       bool IsBoom(const Base &base)const;
       //
       void SetDisappear(bool tmp){m_bDisappear=tmp;}
       //
       QPoint getpos(){return m_pos;}
       //攻击力,攻击类型astyle
       void downlife(float attack);
};

#endif
