#ifndef WAITCLIENTDIALOG_H
#define WAITCLIENTDIALOG_H

#include <QDialog>
#include <QtGui>
#include <QLabel>
namespace Ui {
class WaitClientDialog;
}

class WaitClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaitClientDialog(QWidget *parent = 0);
    ~WaitClientDialog();
    QLabel *labelWait;

private:
    Ui::WaitClientDialog *ui;
};

#endif // WAITCLIENTDIALOG_H
