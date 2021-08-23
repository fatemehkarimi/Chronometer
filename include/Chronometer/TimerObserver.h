#ifndef CHRONOMETER_TIMEROBSERVER_H
#define CHRONOMETER_TIMEROBSERVER_H

#include <QTime>

class TimerObserver : public QObject {
public slots:
    virtual void timeElapsed(QTime remaining) = 0;
    virtual void timerTimeout() = 0;
};

#endif // CHRONOMETER_TIMEROBSERVER_H
