#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    mthread = new QThread();
    Worker *worker = new Worker();
    connect(mthread,&QThread::started,worker,&Worker::DoWork);
    connect(worker,&Worker::Complete,this,&Dialog::complete);
    worker->moveToThread(mthread);
    mthread->start();
}

void Dialog::complete()
{
    Worker *worker = qobject_cast<Worker*>(sender());
    qDebug() << "Complete" << worker;
    worker->deleteLater();
}

