#include "tbmainwindow.h"
#include "ui_tbmainwindow.h"
#include "gradesdialog.h"
#include "mainwindow.h"

TBMainWindow::TBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TBMainWindow)
{
    ui->setupUi(this);
    this->resize(1281,741);
    this->setMaximumSize(1281,741);
    this->setWindowIcon(QIcon(":/new/prefix1/tank.ico"));
    this->setWindowTitle("Tank Battle");
    QPalette palette; //设置背景
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/background2.png").scaled(this->size())));
    this->setPalette(palette);

    startbtn=new QPushButton(this);
    startbtn->setIcon(QIcon(":/new/prefix1/btn1.jpg"));
    startbtn->setToolTip("开始游戏");   //鼠标置于其上显示的文字
    startbtn->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    startbtn->setIconSize(QSize(187,56));//设置图标大小
    startbtn->setGeometry(QRect(40,600,187,56));

    helpbtn=new QPushButton(this);
    helpbtn->setIcon(QIcon(":/new/prefix1/btn2.jpg"));
    helpbtn->setEnabled(true);  //使能
    helpbtn->setToolTip("帮助");   //鼠标置于其上显示的文字
    helpbtn->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    helpbtn->setIconSize(QSize(187,56));
    helpbtn->setGeometry(QRect(290,600,187,56));
    helpbtn->setFlat(true);//使按钮无边框

    aboutbtn=new QPushButton(this);
    aboutbtn->setIcon(QIcon(":/new/prefix1/btn3.jpg"));
    aboutbtn->setEnabled(true);  //使能
    aboutbtn->setToolTip("关于");   //鼠标置于其上显示的文字
    aboutbtn->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    aboutbtn->setIconSize(QSize(187,56));
    aboutbtn->setGeometry(QRect(540,600,187,56));
    aboutbtn->setFlat(true);

    scoreboardbtn=new QPushButton(this);
    scoreboardbtn->setIcon(QIcon(":/new/prefix1/btn4.jpg"));
    scoreboardbtn->setEnabled(true);  //使能
    scoreboardbtn->setToolTip("积分榜");   //鼠标置于其上显示的文字
    scoreboardbtn->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    scoreboardbtn->setIconSize(QSize(187,56));
    scoreboardbtn->setGeometry(QRect(790,600,187,56));
    scoreboardbtn->setFlat(true);

    exitbtn=new QPushButton(this);
    exitbtn->setIcon(QIcon(":/new/prefix1/btn5.jpg"));
    exitbtn->setEnabled(true);  //使能
    exitbtn->setToolTip("退出游戏");   //鼠标置于其上显示的文字
    exitbtn->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    exitbtn->setIconSize(QSize(187,56));
    exitbtn->setGeometry(QRect(1040,600,187,56));
    exitbtn->setFlat(true);
    //设置说明标签
    connect(exitbtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
    connect(startbtn,SIGNAL(clicked()),this,SLOT(startSlot()));
    connect(helpbtn,SIGNAL(clicked()),this,SLOT(helpSlot()));
    connect(scoreboardbtn,SIGNAL(clicked()),this,SLOT(scoreboardSlot()));
    connect(aboutbtn,SIGNAL(clicked()),this,SLOT(aboutSlot()));
}

TBMainWindow::~TBMainWindow()
{
    ui->statusBar->setStyle(QStyleFactory::create("windows"));
    delete exitbtn;
    delete aboutbtn;
    delete helpbtn;
    delete scoreboardbtn;
    delete startbtn;
    delete ui;
}

void TBMainWindow::startSlot()
{
    this->close();
    MainWindow * mw=new MainWindow();
    mw->show();

}
void TBMainWindow::helpSlot()
{
    QMessageBox message(QMessageBox::NoIcon, "Help", "摁键盘“W”“S”“A”“D”分别向“前”“后”“左”“右”移动，摁“J”开火。\n摁“M”并左键点击地图设置障碍物，右键取消障碍物。\n“N”保存地图，“G”回到游戏，“L”清除地图。\n在最短时间内消灭敌人！敌人可能会越来越多！\n你只有一条命！",QMessageBox::Ok);
    message.setWindowIcon(QIcon(":/new/prefix1/tank.ico"));
    message.button(QMessageBox::Ok)->setText("");
    message.button(QMessageBox::Ok)->setIcon(QIcon(":/new/prefix1/ok.png"));
    message.button(QMessageBox::Ok)->setEnabled(true);  //使能
    message.button(QMessageBox::Ok)->setToolTip("朕知道了");   //鼠标置于其上显示的文字
    message.button(QMessageBox::Ok)->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    message.exec();
}
void TBMainWindow::aboutSlot()
{
    QMessageBox message(QMessageBox::NoIcon, "About The Game", "版本：1.0.1 \n开发者:于浩、钟腾 \n联系方式：nkyuhao@163.com ",QMessageBox::Ok);
    message.setWindowIcon(QIcon(":/new/prefix1/tank.ico"));
    message.button(QMessageBox::Ok)->setText("");
    message.button(QMessageBox::Ok)->setIcon(QIcon(":/new/prefix1/ok.png"));
    message.button(QMessageBox::Ok)->setEnabled(true);  //使能
    message.button(QMessageBox::Ok)->setToolTip("朕知道了");   //鼠标置于其上显示的文字
    message.button(QMessageBox::Ok)->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    message.exec();
}
void TBMainWindow::scoreboardSlot()
{
//    GradesDialog *gd=new GradesDialog();
//    gd->exec();
}
void TBMainWindow::exitSlot()
{
    if(QMessageBox::question(this,"Exit The Game","Whether or not to exit the current game?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        delete this;
        exit(0);
    }
}
