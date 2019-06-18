#ifndef GAMEMAP_H
#define GAMEMAP_H

#include"mapcell.h"
#include<QRect>
#include"main.h"
class GameMap
{
private:
Mapcell *cells[INUM][JNUM];
public:
    GameMap();
    ~GameMap();
    Mapcell *getcell(int i,int j)const{return cells[i][j];}
    void Display(QPainter &paint);

    int switchstyle(int i,int j){
        int tmpstyle=0;
        if(i>=INUM||j>=JNUM)
        {qDebug("数组越界");return 0;}
        if(cells[i][j])
        tmpstyle=cells[i][j]->switchstyle();
        else{
            cells[i][j]=new Mapcell(i,j,0);
            tmpstyle=0;
        }
        return tmpstyle;
    }

    void cal(int x,int y,int &i,int &j){//根据鼠标点击位置计算出地图块的二维编号地址
     j=x/CELLWIDTH;
     i=y/CELLHEIGHT;
    }

    void setstyle(int i,int j,int style);
    void deletecell(int i,int j);
    //save map
    void savemap(const char *str);
    //load map
    void loadmap(const char *str);

   //



};

#endif // GAMEMAP_H
