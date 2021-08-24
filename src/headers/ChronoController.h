#ifndef CHRONOCONTROLLER_H
#define CHRONOCONTROLLER_H

#include "headers/TimerObserver.h"
#include "headers/Controller.h"
#include "headers/ChronoView.h"
#include "headers/Timer.h"

class ChronoController : public Controller, public TimerObserver
{    
public:
    ChronoController(Timer* t);
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();
    virtual void timerTimeout();
    virtual void timeElapsed(QTime t);

private:
    Timer * timer;
    ChronoView* view;
    int secondsElapsed = 0;
    int milisecondsElapsed = 0;
};

#endif