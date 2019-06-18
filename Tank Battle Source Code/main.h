#ifndef MAIN
#define MAIN
#define JNUM 17
#define INUM 11
#define PICWIDTH 64//地图块图片宽度
#define PICHEIGHT 64
#define CELLWIDTH 64//地图块宽度
#define CELLHEIGHT 64
#define WIDTH 64*17//地图宽度
#define HEIGHT 64*11
#define PICTANKWIDTH 64//坦克图片宽度
#define PICTANKHEIGHT 64//坦克图片高度
#define TANKWIDTH 64//坦克宽度
#define TANKHEIGHT 64//坦克高度
#define PICBULLETWIDTH 40//zidan图片宽度
#define PICBULLETHEIGHT 40//zidan图片高度
#define BULLETWIDTH 40//zidan宽度
#define BULLETHEIGHT 40//zidan高度
class QImage;
class GameMap;
class Tank;
class Wanwu;
class Bullet;
class Status;
#include<QList>
typedef struct{
unsigned int framei;
QImage *blockimage;
QImage *tankimageup;
QImage *tankimagedown;
QImage *tankimageleft;
QImage *tankimageright;
QImage *bulletimageup;
QImage *bulletimagedown;
QImage *bulletimageleft;
QImage *bulletimageright;
QImage *enemytankup;
QImage *enemytankdown;
QImage *enemytankleft;
QImage *enemytankright;
Status *status;
Tank *player;
GameMap *gamemap;
QList<Tank*> badtanks;
QList<Bullet*> playerbullets;

}Glo;//实列化Glo类型变量，能实列化出来,所有的指针变量所占空间daxiao一样。
extern Glo glo;//声明变量
#endif // MAIN

