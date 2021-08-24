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
    void setInterval(QTime t);
    void start();
    void stop();
    void clear();
    void registerTimerObserver(TimerObserver* observer);

public slots:
    void timeElapsed();

signals:
    void timeout();
    void remainingTime(QTime t);

private:
    const int UNIT_INTERVAL = 1000;
    int interval;
    int remaining_time = 0;
    QTimer* base_timer;
};

#endif // CHRONOMETER_TIMER_H
