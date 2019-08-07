#include "jhr_stdin.h"
#include <iostream>
Jhr_stdin::Jhr_stdin(QObject *parent) : QThread(parent)
{
}
void Jhr_stdin::jhr_stdout(const QString &msg){
    std::cout<<msg.toUtf8().data()<<std::endl;
}
void Jhr_stdin::run(){
    static char buff[500];
    while(true)
   {
      std::cin.getline(buff,500);
      QString strS(buff);
      emit jhr_stdin(strS);
   }
}
