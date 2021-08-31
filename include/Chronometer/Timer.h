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
    void start();
    void stop();
    void clear();
    void registerTimerObserver(TimerObserver* observer);    

    enum ACCURACY {
        MILISEC_1 = 1,
        MILISEC_10 = 100,
        MILISEC_100 = 10,
        SECOND = 1000
    };

    void setTimerAccuracy(ACCURACY u);
    ACCURACY getAccuracy();


public slots:
    void timeElapsed();

signals:
    void timeout();
    void remainingTime(QTime t);

private:
    ACCURACY acc = ACCURACY::SECOND;
    int interval;
    int remaining_time = 0;
    QTimer* base_timer;
};

#endif // CHRONOMETER_TIMER_H
