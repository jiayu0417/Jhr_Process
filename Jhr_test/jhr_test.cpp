#include "jhr_test.h"
#include <QTime>
#include <iostream>
#include <QDebug>
Jhr_test::Jhr_test(QObject *parent) : QObject(parent)
{
    qDebug()<<"Start...\n";
    tim_id_5s = startTimer(5000);
    jhr_stdin = new Jhr_stdin(this);
    jhr_stdin->start();
    connect(jhr_stdin,&Jhr_stdin::jhr_stdin,[=](const QString &msg){
        jhr_stdin->jhr_stdout("rcv:"+ msg);
    });
}
void Jhr_test::timerEvent(QTimerEvent *e){
    if(tim_id_5s == e->timerId()){
        jhr_stdin->jhr_stdout(QTime::currentTime().toString());
        return;
    }
}
