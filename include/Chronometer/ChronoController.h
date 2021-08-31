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
    void stopTimer();
    void resetTimer();

private:
    Timer* timer;
    ChronoView* view;
    QThread* timer_thread;
    QTime maximum_time;
    bool isStartCommand = true;
    bool isTimerPending = false;
};

#endif // #include <Chronometer/ChronoView.h>
