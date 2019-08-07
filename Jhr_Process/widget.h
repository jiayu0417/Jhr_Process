#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_cmdSend_clicked();
private:
    Ui::Widget *ui;
    QProcess *process;
    void proc_readyReadStandardOutput(QProcess *);
    void proc_readyReadStandardError(QProcess *);
    void closeEvent(QCloseEvent*);

};

#endif // WIDGET_H
