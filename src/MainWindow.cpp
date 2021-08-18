#include <QtWidgets>
#include "headers/MainWindow.h"

MainWindow::MainWindow(Controller* time_controller, int width, int height, QString title) {
    this->window = new QTabWidget();
    this->window->resize(width, height);
    this->window->setWindowTitle(title);
    
    timer_window = new TimerWindow(time_controller);
    this->window->addTab(timer_window->getWindow(), "Timer");
}

void MainWindow::show() {
    this->window->show();
}

TimerWindow* MainWindow::getTimerWindow() {
    return this->timer_window;
}