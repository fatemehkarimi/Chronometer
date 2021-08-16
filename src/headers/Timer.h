#include <QTime>
#include <QTimer>
#include <QThread>
#include <QtWidgets>

class Timer : public QObject
{
    Q_OBJECT

public:
    Timer(QTime initial);

public slots:
    void start();
    void timeout();
    void timeElapsed();

private:
    int interval;
    QThread worker;
    QTimer* main_timer;
    QTimer* base_timer;
};