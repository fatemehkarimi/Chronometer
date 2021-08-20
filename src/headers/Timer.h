#ifndef TIMER_H
#define TIMER_H

#include <QTime>
#include <QTimer>
#include <QThread>
#include <QtWidgets>
#include "headers/TimerObserver.h"

class Timer : public QObject
{
    Q_OBJECT

public:
    Timer();
    void setInterval(QTime t);
    void start();
    void stop();
    void registerRemainingTimeObserver(TimerObserver* observer);

public slots:
    void timeout();
    void timeElapsed();

signals:
    void remainingTime(QTime t);
    
private:
    const int UNIT_INTERVAL = 1000;
    int interval;
    int remaining_time = 0;
    QThread worker;
    QTimer* base_timer;
};

#endif