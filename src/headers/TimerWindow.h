#include <QtWidgets>
#include <QGridLayout>

class TimerWindow {
public:
    TimerWindow();
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);

private:
    QWidget* timer_window;
};