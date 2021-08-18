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
    QLineEdit* setupTimeInput(QString object_name);
    QProgressBar* getProgressBar();
    QTime readInput();

public slots:
    void handleStartButton();
    void handleResetButton();

private:
    QWidget* timer_window;
    Controller* controller;
};