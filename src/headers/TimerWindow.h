#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QtWidgets>
#include <QGridLayout>
#include <QProgressBar>
#include "headers/Timer.h"
#include "headers/Controller.h"
#include "headers/TimerObserver.h"

class TimerWindow : public TimerObserver
{
    Q_OBJECT

public:
    TimerWindow(Controller* controller, Timer* timer);
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* setupTimeInput(QString object_name);
    QProgressBar* getProgressBar();
    QTime readInput();
    void rejectInput();
    QTime makeTimeInputStandard(int h, int m, int s);
    void updateTime(QTime t);
    QString makeOutputStandard(int o);

public slots:
    void handleStartButton();
    void handleResetButton();
    virtual void timeElapsed(QTime remaining);

private:
    Timer* timer;
    QWidget* timer_window;
    Controller* controller;
};

#endif