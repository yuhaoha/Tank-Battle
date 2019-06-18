#ifndef TBMAINWINDOW_H
#define TBMAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtGui>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QFont>
#include <QStyleFactory>
#include<mainwindow.h>
namespace Ui {
class TBMainWindow;
}

class TBMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TBMainWindow(QWidget *parent = 0);

    ~TBMainWindow();
private:
    Ui::TBMainWindow *ui;
    QPushButton *startbtn;
    QPushButton *exitbtn;
    QPushButton *helpbtn;
    QPushButton *scoreboardbtn;
    QPushButton *aboutbtn;
    TBMainWindow *g;
    QLabel *label;
signals:
public slots:
    void exitSlot();
    void startSlot();
    void scoreboardSlot();
    void helpSlot();
    void aboutSlot();
};

#endif // TBMAINWINDOW_H
