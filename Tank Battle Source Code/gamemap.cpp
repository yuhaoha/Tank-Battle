#include "gamemap.h"

GameMap::GameMap()
{
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
        cells[i][j]=NULL;
//for(int i=0;i<INUM;i++)
   // for(int j=0;j<JNUM;j++)
       //cells[i][j]=new Mapcell(i,j,0);
loadmap("1.dat");
}\
GameMap::~GameMap(){
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
            if(cells[i][j])
           {cells[i][j]=NULL;
             //   delete cells[i][j] ;
               }
}

void GameMap::Display(QPainter &paint){

paint.drawImage(QRect(0,0,WIDTH,HEIGHT),QImage(":/new/prefix1/background4.jpeg"));
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
    {
        if(cells[i][j]!=NULL)
            cells[i][j]->Display(paint);

    }

}


void GameMap::setstyle(int i, int j, int style){
    if(i>=INUM||j>=JNUM)
    {qDebug("数组越界");return ;}
     if(cells[i][j])
         cells[i][j]->setstyle(style);
     else{
         cells[i][j]=new Mapcell(i,j,style);

     }
}


void GameMap::deletecell(int i, int j){
    if(i>=INUM||j>=JNUM)
    {qDebug("数组越界");return;}
    //delete cells[i][j];
   cells[i][j]=NULL;
}


void GameMap::savemap(const char *str){
//erjinzhi
    std::ofstream ou(str);
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
             if(cells[i][j]&&!cells[i][j]->IsDisappear())
             ou.write((char*)cells[i][j],sizeof(Mapcell));
ou.close();
}

void GameMap::loadmap(const char *str){
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
            if(cells[i][j])
           {//delete cells[i][j] ;
                cells[i][j]=NULL;}

Mapcell cellst;
std::ifstream in(str);
int i=0,j=0;
   while(in.read((char*)&cellst,sizeof(Mapcell)))
      { j=cellst.getpos().x()/CELLWIDTH;
        i=cellst.getpos().y()/CELLHEIGHT;
        if(cells[i][j])
        *cells[i][j]=cellst;
            else
             {
             cells[i][j]=new Mapcell(i,j);
             *cells[i][j]=cellst;//moren de 赋值 gou zao hanshu
             }

       }
in.close();
}
