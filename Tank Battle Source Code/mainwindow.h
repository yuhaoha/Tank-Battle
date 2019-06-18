
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QTimer>
#include<fstream>
#include"main.h"
#include "gamemap.h"
#include"tank.h"
#include"bullet.h"
#include"status.h"
#include<QMediaPlayer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Gamestatus{mapedit,gameing,pause};//游戏状态
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMediaPlayer *sound;
private slots:
void keyPressEvent(QKeyEvent *event);
void keyReleaseEvent(QKeyEvent *event);
void mouseMoveEvent(QMouseEvent *event);
void mousePressEvent(QMouseEvent *event);
void paintEvent(QPaintEvent *event);
void timefun();
private:
int leftorright;//左右
int laststyle;//上一次方块样式
double time_Start;
void setgame(Gamestatus status){gamestatus=status;}//设置游戏状态
Gamestatus gamestatus;

QTimer *timer;

QPainter paint;
};

#endif // MAINWINDOW_H
