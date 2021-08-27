#ifndef CHRONOMETER_TIMER_H
#define CHRONOMETER_TIMER_H

#include <QTime>
#include <QTimer>
#include <QtWidgets>

#include <Chronometer/TimerObserver.h>

class Timer : public QObject {
    Q_OBJECT

public:
    Timer();
    Q_INVOKABLE void setInterval(QTime t);
    void stop();
    void clear();
    void registerTimerObserver(TimerObserver* observer);    

    enum UNIT {
        MILISECOND = 100,
        SECOND = 1000
    };

    void setTimerUnit(UNIT u);


public slots:
    void start();
    void timeElapsed();

signals:
    void timeout();
    void remainingTime(QTime t);

private:
    UNIT unit = UNIT::SECOND;
    int interval;
    int remaining_time = 0;
    QTimer* base_timer;
};

#endif // CHRONOMETER_TIMER_H
