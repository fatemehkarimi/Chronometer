#include <QtWidgets>
#include "headers/Controller.h"
#include "headers/TimerWindow.h"

class MainWindow {
public:
    MainWindow(Controller * time_controller, int width, int height, QString title);
    TimerWindow* getTimerWindow();
    void show();

private:
    QTabWidget* window;
    TimerWindow* timer_window;
};