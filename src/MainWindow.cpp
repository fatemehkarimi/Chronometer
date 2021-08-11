#include <QtWidgets>
#include "MainWindow.h"

MainWindow::MainWindow(int width, int height, QString title) {
    this->window = new QWidget();
    this->window->resize(width, height);
    this->window->setWindowTitle(title);
}

void MainWindow::show() {
    this->window->show();
}