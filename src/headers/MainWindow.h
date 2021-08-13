#include <QtWidgets>
#include "headers/TimerWindow.h"

class MainWindow {
public:
    MainWindow(int width, int height, QString title);
    void show();

private:
    QTabWidget* window;
};