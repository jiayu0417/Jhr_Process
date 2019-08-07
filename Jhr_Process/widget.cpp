#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process,&QProcess::readyReadStandardOutput,[=](){proc_readyReadStandardOutput(process);});
    connect(process,&QProcess::readyReadStandardError,[=](){proc_readyReadStandardError(process);});
    QStringList sL;
    if(process->state() != QProcess::NotRunning)process->kill();
    process->start("./Jhr_test",sL);
}
QString rcv_handle(QByteArray &bA){
   /* QString strRcv(bA);
    QStringList list =strRcv.split(" ", QString::SkipEmptyParts);
    if(list.size() < 2)return "";
    if(list.at(0).compare("Response:"))return strRcv;
    if(list.at(0).compare("You") && list.at(1).compare("Said:"))return strRcv;
    return "";*/
    return QString(bA);
}
void Widget::proc_readyReadStandardOutput(QProcess *pro){
    QByteArray bA = pro->readAllStandardOutput();
    QString strR = rcv_handle(bA);
    if(strR.length() > 0){
        if(ui->txtRcv->toPlainText().size() > 10000)ui->txtRcv->clear();
        ui->txtRcv->append(bA);
    }
}
void Widget::proc_readyReadStandardError(QProcess *pro){
    QByteArray bA = pro->readAllStandardError();
    ui->txtRcv->append(bA);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::closeEvent(QCloseEvent*){
    process->close();
    //qDebug()<<"退出完成";
}
void Widget::on_cmdSend_clicked()
{
    if(process->state() == QProcess::Running){
        QString strS= ui->txtSend->text() + "\r\n";
        process->write(strS.toUtf8());
    }
}
