#include <QApplication>

#include <Chronometer/ChronoController.h>
#include <Chronometer/MainWindow.h>
#include <Chronometer/TimeController.h>
#include <Chronometer/Timer.h>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow* window = new MainWindow(700, 700, "Chronometer");
    // Timer
    Timer* timer = new Timer();
    Controller* time_controller = new TimeController(timer);
    window->registerWindow(time_controller->getView(), "Timer");

    // Chronometer
    Controller* chrono_controller = new ChronoController();
    window->registerWindow(chrono_controller->getView(), "Chronometer");

    window->show();
    return app.exec();
}
