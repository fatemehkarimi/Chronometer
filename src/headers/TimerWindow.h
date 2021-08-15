#include <QtWidgets>
#include <QGridLayout>
#include <QProgressBar>

class TimerWindow {
public:
    TimerWindow();
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* getTimeInput();
    QProgressBar* getProgressBar();


private:
    QWidget* timer_window;
};