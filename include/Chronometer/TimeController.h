#ifndef CHRONOMETER_TIMECONTROLLER_H
#define CHRONOMETER_TIMECONTROLLER_H

#include <QTime>

#include <Chronometer/Controller.h>
#include <Chronometer/Timer.h>
#include <Chronometer/TimerWindow.h>

class TimeController : public Controller
    , public TimerObserver {
public:
    explicit TimeController(Timer* t);
    void setTime(QTime t);
    void start() override;
    void stop() override;
    void reset() override;
    QWidget* getView() override;
    void timerTimeout() override;
    void timeElapsed(QTime) override { }

private:
    Timer* timer;
    TimerWindow* timer_window;
    bool isStartCommand = true;
    bool isTimerPendig = false;
    QTime currentInterval = QTime(0, 0, 0);
};

#endif // CHRONOMETER_TIMECONTROLLER_H
