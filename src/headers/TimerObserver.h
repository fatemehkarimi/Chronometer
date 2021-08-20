#ifndef TIMEROBSERVER_H
#define TIMEROBSERVER_H
#include <QTime>

class TimerObserver : public QObject {
public slots:
    virtual void timeElapsed(QTime remaining) = 0;
    virtual void timerTimeout() = 0;
};

#endif