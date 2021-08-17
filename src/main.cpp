#include <QApplication>
#include "headers/MainWindow.h"
#include "headers/TimeController.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Controller* time_controller = new TimeController();
    MainWindow* window = new MainWindow(time_controller, 700, 700, "Chronometer");
    window->show();
    return app.exec();
}