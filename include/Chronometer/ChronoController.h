#ifndef CHRONOMETER_CHRONOCONTROLLER_H
#define CHRONOMETER_CHRONOCONTROLLER_H

#include <Chronometer/Timer.h>
#include <Chronometer/ChronoView.h>
#include <Chronometer/Controller.h>
#include <Chronometer/TimerObserver.h>

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