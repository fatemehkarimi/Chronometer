#include <QtWidgets>
#include <QGridLayout>
#include <QProgressBar>
#include "headers/Controller.h"
#include "headers/TimerObserver.h"

class TimerWindow : public TimerObserver
{
    Q_OBJECT

public:
    TimerWindow(Controller* controller);
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* setupTimeInput(QString object_name);
    QProgressBar* getProgressBar();
    QTime readInput();
    void rejectInput();
    QTime makeInputStandard(int h, int m, int s);
    void updateTime(QTime t);

public slots:
    void handleStartButton();
    void handleResetButton();
    virtual void timeElapsed(QTime remaining);

private:
    QWidget* timer_window;
    Controller* controller;
};