#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include <QTime>
#include "headers/Timer.h"
#include "headers/Controller.h"
#include "headers/TimerWindow.h"

class TimeController : public Controller, public TimerObserver
{
public:
    TimeController(Timer* t);
    virtual void setTime(QTime t);
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();
    virtual void timerTimeout();
    virtual void timeElapsed(QTime t) {}

private:
    Timer* timer;
    TimerWindow* timer_window;
    bool isStartCommand = true;
    bool isTimerPendig = false;
    QTime currentInterval = QTime(0, 0, 0);
};

#endif