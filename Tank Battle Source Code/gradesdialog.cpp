#include "gradesdialog.h"
#include "ui_gradesdialog.h"
#include <QSqlQuery>
#include <QFont>
#include<QDebug>
GradesDialog::GradesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GradesDialog)
{
    ui->setupUi(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    this->setWindowTitle("score board");
    this->setWindowIcon(QIcon(":/new/prefix1/tank.ico"));
    QPalette palette; //设置背景
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/timg.jpg").scaled(this->size())));
    this->setPalette(palette);
    this->select();
    ui->button->setIcon(QIcon(":/new/prefix1/ok.png"));
    ui->button->setEnabled(true);  //使能
    ui->button->setToolTip("朕知道了");
    ui->button->setCursor(QCursor(Qt::PointingHandCursor)); //鼠标置于其上成为手型
    ui->button->setFlat(true);
}

GradesDialog::~GradesDialog()
{
    delete ui;
}

void GradesDialog:: select ()
{
    QFont ft;
    ft.setPointSize(12);
    ui->label1->setFont(ft);
    ui->label2->setFont(ft);
    ui->label3->setFont(ft);
    ui->label4->setFont(ft);
    ui->label5->setFont(ft);
    ui->label6->setFont(ft);
    ui->label7->setFont(ft);
    ui->label8->setFont(ft);
    ui->label9->setFont(ft);
    ui->label10->setFont(ft);
    ui->label11->setFont(ft);
    ui->label12->setFont(ft);
    ui->label13->setFont(ft);
    ui->label14->setFont(ft);
    ui->label15->setFont(ft);
    QSqlQuery query;
    query.exec("select * from grades order by grade ");
    int i=0;
    QString name[5];
    double grade[5];
    while (query.next()&&i<5)
    {
        name[i]=query.value(1).toString();
        grade[i]=query.value(2).toDouble();
        i++;
    }
    ui->label2->setText(name[0]);
    ui->label5->setText(name[1]);
    ui->label8->setText(name[2]);
    ui->label11->setText(name[3]);
    ui->label14->setText(name[4]);
    ui->label3->setText(QString("%1").arg(grade[0]));
    ui->label6->setText(QString("%1").arg(grade[1]));
    ui->label9->setText(QString("%1").arg(grade[2]));
    ui->label12->setText(QString("%1").arg(grade[3]));
    ui->label15->setText(QString("%1").arg(grade[4]));
}



void GradesDialog::on_button_clicked()
{
    this->close();
}
