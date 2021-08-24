#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QtWidgets>
#include <QGridLayout>
#include <QProgressBar>
#include "headers/Timer.h"
#include "headers/TabWindow.h"
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
    void setFontSizeForItems();
    virtual void timeElapsed(QTime remaining);
    virtual void timerTimeout();

private:
    Timer* timer;
    TabWindow* timer_window;
    Controller* controller;
    QMetaObject::Connection windowConnection;
};

#endif