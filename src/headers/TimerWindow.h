#include <QtWidgets>
#include <QGridLayout>

class TimerWindow {
public:
    TimerWindow();
    QWidget* getWindow();
    void designTimeLayout(QGridLayout* time_layout);
    QLineEdit* getTimeInput();

private:
    QWidget* timer_window;
};