#include <QApplication>
#include "headers/MainWindow.h"

#include <QTime>
#include "headers/Timer.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow* window = new MainWindow(700, 700, "Chronometer");
    window->show();
    return app.exec();
}