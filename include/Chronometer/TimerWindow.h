#ifndef CHRONOMETER_TIMERWINDOW_H
#define CHRONOMETER_TIMERWINDOW_H

#include <QGridLayout>
#include <QProgressBar>
#include <QtWidgets>

#include <Chronometer/Controller.h>
#include <Chronometer/Timer.h>
#include <Chronometer/TimerObserver.h>

class TimerWindow : public TimerObserver {
    Q_OBJECT

public:
    TimerWindow(Controller* controller, Timer* timer);
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* setupTimeInput(QString object_name);
    QTime readInput();
    QTime makeTimeInputStandard(int h, int m, int s);
    void updateTime(QTime t);
    QString makeOutputStandard(int o);
    void setStartButton();
    void setStopButton();
    void updateProgressBar(int value);
    void resetProgressBar();
    void setProgressBarMaximum(int max);

public slots:
    void handleStartButton();
    void handleResetButton();
    virtual void timeElapsed(QTime remaining);
    virtual void timerTimeout();

private:
    Timer* timer;
    QWidget* timer_window;
    Controller* controller;
};

#endif // CHRONOMETER_TIMERWINDOW_H
