#include "tank.h"

Tank::Tank()
{
    this->m_pos.setX(10*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(8*CELLHEIGHT+CELLHEIGHT/2);
    this->wuli=100;
    this->group=0;//0玩家组，1敌人组
    style=0;
    m_step=8;
    gongjijiange=8;
    ismove=false;
    m_dir=UP;
    isfire=false;
    m_bDisappear=false;
    life=100;
    CalculateSphere();
}


Tank::Tank(int iIndex,int jIndex,Dir dir,int group){
    this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
    this->m_dir=dir;
    this->group=group;
    isfire=false;
    wuli=1;  //伤害
    m_step=5;  //移动速度
    gongjijiange=15; //攻速
    style=3;
    m_bDisappear=false;
    life=100;     //生命值
    CalculateSphere();
}




void Tank::Display(QPainter &paint){
    for(int i=0;i<bullets.count();i++)
        if(bullets.at(i)&&!bullets.at(i)->IsDisappear())
    bullets.at(i)->Display(paint);
        else if(bullets.at(i)){
            //delete bullets.at(i);//回收new出来的对象空间
            bullets.removeAt(i);//将对象指针从链表删除
            i--;
        }

    QRect xm_rectSphere=m_rectSphere;
    if(m_bDisappear)return;
    if(this->group==0){
    switch(m_dir){
        case UP:

          // paint.drawImage(m_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(m_rectSphere,*glo.tankimageup,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
          // paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case DOWN:
             paint.drawImage(m_rectSphere,*glo.tankimagedown,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
          //  paint.drawImage(m_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
         //   paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case LEFT:
              paint.drawImage(m_rectSphere,*glo.tankimageleft,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
        //    paint.drawImage(m_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
        //    paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case RIGHT:
              paint.drawImage(m_rectSphere,*glo.tankimageright,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
          //  paint.drawImage(m_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
          //  paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
      }
}
    else if(this->group==1){
        switch(m_dir){
            case UP:

              // paint.drawImage(m_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
                paint.drawImage(m_rectSphere,*glo.enemytankup,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
              // paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
                break;
            case DOWN:
                 paint.drawImage(m_rectSphere,*glo.enemytankdown,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
              //  paint.drawImage(m_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
             //   paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
                break;
            case LEFT:
                  paint.drawImage(m_rectSphere,*glo.enemytankleft,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            //    paint.drawImage(m_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            //    paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
                break;
            case RIGHT:
                  paint.drawImage(m_rectSphere,*glo.enemytankright,QRect(0*PICTANKWIDTH,0*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
              //  paint.drawImage(m_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
              //  paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
                break;
          }
    }
}
void Tank::Move()
{
    for(int i=0;i<bullets.count();i++)
    bullets.at(i)->Move();
   if(m_bDisappear)return ;
   if(nextsiboom())return;
   if(ismove==true){
    switch(m_dir){
        case UP:
            m_pos.setY(m_pos.y()-m_step);
            break;
        case DOWN:
            m_pos.setY(m_pos.y()+m_step);
            break;
        case LEFT:
            m_pos.setX(m_pos.x()-m_step);
            break;
        case RIGHT:
            m_pos.setX(m_pos.x()+m_step);
            break;
      }
    CalculateSphere();
    qDebug("move on");
 }
qDebug("move off");
}

void Tank::Move1()//和move一样，为了避免死循环
{
   if(ismove==true){
    switch(m_dir){
        case UP:
            m_pos.setY(m_pos.y()-m_step);
            break;
        case DOWN:
            m_pos.setY(m_pos.y()+m_step);
            break;
        case LEFT:
            m_pos.setX(m_pos.x()-m_step);
            break;
        case RIGHT:
            m_pos.setX(m_pos.x()+m_step);
            break;
      }
    CalculateSphere();
    qDebug("yuce ");
 }
qDebug("move off");
}


bool Tank::nextsiboom(){
 Tank tmp=*this;
 tmp.Move1();
 //qDebug("%d",tmp.m_rectSphere.right());
 //qDebug("%d",glo.gamemap->getcell(1,4)->m_rectSphere.left());
 //是否与地图块碰撞
 for(int i=0;i<INUM;i++)
     for(int j=0;j<JNUM;j++)
         if(glo.gamemap->getcell(i,j)&&!glo.gamemap->getcell(i,j)->ischuantou()&&tmp.IsBoom(*glo.gamemap->getcell(i,j))){
            qDebug("-----------boom-------"); return true;
         }
 qDebug("---------------");
 //是否与地图边界碰撞
 if(tmp.m_rectSphere.left()<0||tmp.m_rectSphere.right()>WIDTH||tmp.m_rectSphere.bottom()>HEIGHT||tmp.m_rectSphere.top()<0)
 return true;//

 return false;
}


void Tank::fire(){
    if(m_bDisappear)return;
if(isfire==true&&glo.framei%gongjijiange==0){
Bullet *newbullet=new Bullet(*this);
bullets.append(newbullet);
}

}


void Tank::startfire(){

    isfire=true;

}

void Tank::stopfire(){



    isfire=false;
}



void Tank::CalculateSphere(){

this->m_rectSphere.setRect(m_pos.x()-TANKWIDTH/2,m_pos.y()-TANKHEIGHT/2,TANKWIDTH,TANKHEIGHT);

}
