#ifndef CHRONOMETER_TIMECONTROLLER_H
#define CHRONOMETER_TIMECONTROLLER_H

#include <QTime>

#include <Chronometer/Controller.h>
#include <Chronometer/Timer.h>
#include <Chronometer/TimerWindow.h>

class TimeController : public Controller
    , public TimerObserver {
public:
    TimeController(Timer* t);
    void setTime(QTime t);
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();
    virtual void timerTimeout();
    virtual void timeElapsed(QTime) { }

private:
    Timer* timer;
    TimerWindow* timer_window;
    bool isStartCommand = true;
    bool isTimerPendig = false;
    QTime currentInterval = QTime(0, 0, 0);
};

#endif // CHRONOMETER_TIMECONTROLLER_H
