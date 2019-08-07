#ifndef JHR_TEST_H
#define JHR_TEST_H

#include <QObject>
#include "jhr_stdin.h"
#include <QTimerEvent>
class Jhr_test : public QObject
{
    Q_OBJECT
public:
    explicit Jhr_test(QObject *parent = nullptr);

private :
    int tim_id_5s;
    void timerEvent(QTimerEvent *);
    Jhr_stdin *jhr_stdin;
};

#endif // JHR_TEST_H
