#include <QtWidgets>
#include "headers/MainWindow.h"

MainWindow::MainWindow(int width, int height, QString title) {
    this->window = new QTabWidget();
    this->window->resize(width, height);
    this->window->setWindowTitle(title);
    this->window->setFixedSize(QSize(width, height));
}

void MainWindow::show() {
    this->window->show();
}

void MainWindow::registerWindow(QWidget* window, QString tab_name) {
    this->window->addTab(window, tab_name);
}