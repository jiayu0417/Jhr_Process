#include <QCoreApplication>
#include "jhr_test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Jhr_test jhr_s;
    return a.exec();
}
