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
    int interval;
    QThread worker;
    QTimer* main_timer;
    QTimer* base_timer;
};

#endif