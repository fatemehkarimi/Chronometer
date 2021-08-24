#include <QApplication>

#include <Chronometer/ChronoController.h>
#include <Chronometer/MainWindow.h>
#include <Chronometer/TimeController.h>
#include <Chronometer/Timer.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow window(700, 700, "Chronometer");

    // Timer
    Timer t_timer;
    TimeController time_controller(&t_timer);
    window.registerWindow(time_controller.getView(), "Timer");

    // Chronometer
    Timer c_timer;
    ChronoController chrono_controller(&c_timer);

    window.registerWindow(chrono_controller.getView(), "Chronometer");
    window.show();

    return app.exec();
}
