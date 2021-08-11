#include <QtWidgets>
#include "TimerWindow.h"
#include "ChronoWindow.h"

class MainWindow {
public:
    MainWindow(int width, int height, QString title);
    void show();

private:
    QTabWidget* window;
    TimerWindow* timer_window;
    ChronoWindow* chrono_window;
};