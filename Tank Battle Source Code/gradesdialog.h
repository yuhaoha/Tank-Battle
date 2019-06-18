#ifndef GRADESDIALOG_H
#define GRADESDIALOG_H

#include <QDialog>

namespace Ui {
class GradesDialog;
}

class GradesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GradesDialog(QWidget *parent = 0);
    ~GradesDialog();
    void select();
private slots:


    void on_button_clicked();

private:
    Ui::GradesDialog *ui;
};

#endif // GRADESDIALOG_H
