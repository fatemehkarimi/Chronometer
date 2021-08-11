#include <QtWidgets>
#include "MainWindow.h"

MainWindow::MainWindow(int width, int height, QString title) {
    this->window = new QTabWidget();
    this->window->resize(width, height);
    this->window->setWindowTitle(title);    

    this->timer_window = new TimerWindow();
    this->window->addTab(this->timer_window, "Timer");

    this->chrono_window = new ChronoWindow();
    this->window->addTab(this->chrono_window, "Chronometer");
}

void MainWindow::show() {
    this->window->show();
}