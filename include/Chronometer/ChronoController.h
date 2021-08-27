#ifndef CHRONOMETER_CHRONOCONTROLLER_H
#define CHRONOMETER_CHRONOCONTROLLER_H

#include <QThread>
#include <Chronometer/ChronoView.h>
#include <Chronometer/Controller.h>
#include <Chronometer/Timer.h>
#include <Chronometer/TimerObserver.h>

class ChronoController : public TimerObserver
    , public Controller
{
        Q_OBJECT
public:
    explicit ChronoController(Timer* t);
    void start() override;
    void stop() override;
    void reset() override;
    QWidget* getView() override;
    void timerTimeout() override;
    void timeElapsed(QTime t) override;

signals:
    void startTimer();

private:
    Timer* timer;
    ChronoView* view;
    int secondsElapsed = 0;
    QTime second;
    QThread* timer_thread;

    int diff = 0;
};

#endif // #include <Chronometer/ChronoView.h>
