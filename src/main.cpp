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
