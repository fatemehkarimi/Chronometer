#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

#include "headers/Timer.h"
#include "headers/Controller.h"
#include "headers/TimerWindow.h"

class TimeController : public Controller
{
public:
    TimeController(Timer* t);
    virtual void setTime(QTime t);
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();

private:
    Timer* timer;
    TimerWindow* timer_window;
};

#endif