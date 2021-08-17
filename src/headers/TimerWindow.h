#include <QtWidgets>
#include <QGridLayout>
#include <QProgressBar>
#include "headers/Controller.h"

class TimerWindow : public QObject
{
    Q_OBJECT

public:
    TimerWindow(Controller* controller);
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* getTimeInput();
    QProgressBar* getProgressBar();

public slots:
    void handleStartButton();
    void handleResetButton();

private:
    QWidget* timer_window;
    Controller* controller;
};