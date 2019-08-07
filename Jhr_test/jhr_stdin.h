#ifndef JHR_STDIN_H
#define JHR_STDIN_H
#include <QThread>

class Jhr_stdin:public QThread
{
    Q_OBJECT
signals:
    void jhr_stdin(const QString &info);
public:
    explicit Jhr_stdin(QObject *parent = nullptr);
    void jhr_stdout(const QString &msg);
    void run();
};

#endif // JHR_STDIN_H
