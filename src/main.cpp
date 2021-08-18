#include <QApplication>
#include "headers/Timer.h"
#include "headers/MainWindow.h"
#include "headers/TimeController.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Timer* timer = new Timer();
    Controller* time_controller = new TimeController(timer);
    MainWindow* window = new MainWindow(time_controller, 700, 700, "Chronometer");
    timer->registerRemainingTimeObserver(window->getTimerWindow());
    window->show();
    return app.exec();
}