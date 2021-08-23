#ifndef CHRONOMETER_MAINWINDOW_H
#define CHRONOMETER_MAINWINDOW_H

#include <QtWidgets>

#include <Chronometer/Controller.h>
#include <Chronometer/TimerWindow.h>

class MainWindow {
public:
    MainWindow(int width, int height, QString title);
    void show();
    void registerWindow(QWidget* window, QString tab_name);

private:
    QTabWidget* window;
};

#endif // CHRONOMETER_MAINWINDOW_H
