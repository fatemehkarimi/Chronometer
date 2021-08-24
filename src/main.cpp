#include <QApplication>
#include "headers/Timer.h"
#include "headers/MainWindow.h"
#include "headers/TimeController.h"
#include "headers/ChronoController.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow* window = new MainWindow(700, 700, "Chronometer");
    // Timer
    Timer* t_timer = new Timer();
    Controller* time_controller = new TimeController(t_timer);
    window->registerWindow(time_controller->getView(), "Timer");

    // Chronometer
    Timer* c_timer = new Timer();
    Controller* chrono_controller = new ChronoController(c_timer);
    window->registerWindow(chrono_controller->getView(), "Chronometer");

    window->show();
    return app.exec();
}