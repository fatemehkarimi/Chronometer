#include <QtWidgets>
#include "headers/Controller.h"
#include "headers/TimerWindow.h"

class MainWindow {
public:
    MainWindow(int width, int height, QString title);
    void show();
    void registerWindow(QWidget* window, QString tab_name);

private:
    QTabWidget* window;
};