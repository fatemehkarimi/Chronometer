#ifndef CHRONOMETER_CHRONOCONTROLLER_H
#define CHRONOMETER_CHRONOCONTROLLER_H

#include <Chronometer/ChronoView.h>
#include <Chronometer/Controller.h>
#include <Chronometer/Timer.h>
#include <Chronometer/TimerObserver.h>

class ChronoController : public Controller
    , public TimerObserver {
public:
    explicit ChronoController(Timer* t);
    void start() override;
    void stop() override;
    void reset() override;
    QWidget* getView() override;
    void timerTimeout() override;
    void timeElapsed(QTime t) override;

private:
    Timer* timer;
    ChronoView* view;
    int secondsElapsed = 0;
    QTime second;
};

#endif // #include <Chronometer/ChronoView.h>
