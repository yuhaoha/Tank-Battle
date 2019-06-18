#include "bullet.h"
#include"status.h"

Bullet::Bullet(const Tank &tank)
{
    m_dir=tank.m_dir;
    m_pos=tank.m_pos;
    style=tank.style/2;
    m_step=tank.m_step+10;
    wuli=tank.wuli;
    group=tank.group;
    m_bDisappear=false;
CalculateSphere();
}

void Bullet::Display(QPainter &paint){
   if(m_bDisappear==true)return;
    switch(m_dir){
        case UP:

           paint.drawImage(m_rectSphere,*glo.bulletimageup,QRect(0*PICBULLETWIDTH,0*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
           //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(2*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case DOWN:
            paint.drawImage(m_rectSphere,*glo.bulletimagedown,QRect(0*PICBULLETWIDTH,0*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(0*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case LEFT:
            paint.drawImage(m_rectSphere,*glo.bulletimageleft,QRect(0*PICBULLETWIDTH,0*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(1*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case RIGHT:
            paint.drawImage(m_rectSphere,*glo.bulletimageright,QRect(0*PICBULLETWIDTH,0*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(3*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
      }



}




void Bullet::Move(){


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

//子弹是否与地图块碰撞
     for(int i=0;i<INUM;i++)
         for(int j=0;j<JNUM;j++)
          if(glo.gamemap->getcell(i,j))
           if(!glo.gamemap->getcell(i,j)->ischuantou1())
          if(IsBoom(*glo.gamemap->getcell(i,j)))
          {glo.gamemap->getcell(i,j)->downlife(wuli);m_bDisappear=true;
          //    if(group==0)
          //*glo.status=Status(*glo.gamemap->getcell(i,j));

          }

//子弹是否击中敌对坦克
     for(int i=0;i<glo.badtanks.count();i++)
     if(glo.badtanks.at(i)&&glo.badtanks.at(i)->group!=this->group&&IsBoom(*glo.badtanks.at(i)))
     {

        m_bDisappear=true;//子弹消失
        glo.badtanks.at(i)->downlife(wuli);
        if(glo.badtanks.at(i)->life==0)glo.badtanks.removeAt(i);
        //*glo.status=Status(*glo.badtanks.at(i));//将打中的对象的血量显示出来

     }

     if(glo.player->group!=this->group&&IsBoom(*glo.player))
     {

         m_bDisappear=true;//子弹消失
         glo.player->downlife(wuli);
         //*glo.status=Status(*glo.player);//将打中的对象的血量显示出来

     }


//子弹出界
     if(m_pos.x()<0||m_pos.x()>WIDTH||m_pos.y()>HEIGHT||m_pos.y()<0)
         m_bDisappear=true;//子弹消失


}




void Bullet::CalculateSphere(){


this->m_rectSphere.setRect(m_pos.x()-BULLETWIDTH/2,m_pos.y()-BULLETHEIGHT/2,BULLETWIDTH,BULLETHEIGHT);

}
