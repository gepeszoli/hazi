#include "waitclientdialog.h"
#include "ui_waitclientdialog.h"

WaitClientDialog::WaitClientDialog(QWidget *parent) :
    QDialog(parent)
{
    resize(217, 103);
    labelWait = new QLabel(this);
    labelWait->setText("Waiting for client to connect");
    labelWait->setGeometry(QRect(20, 30, 181, 41));
}

WaitClientDialog::~WaitClientDialog()
{
}
