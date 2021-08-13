#include <QtWidgets>
#include "headers/MainWindow.h"

MainWindow::MainWindow(int width, int height, QString title) {
    this->window = new QTabWidget();
    this->window->resize(width, height);
    this->window->setWindowTitle(title);
    
    TimerWindow* timer_window = new TimerWindow();
    this->window->addTab(timer_window->getWindow(), "Timer");
}

void MainWindow::show() {
    this->window->show();
}